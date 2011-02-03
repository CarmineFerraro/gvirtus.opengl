/*
 * gVirtuS -- A GPGPU transparent virtualization component.
 *
 * Copyright (C) 2009-2010  The University of Napoli Parthenope at Naples.
 *
 * This file is part of gVirtuS.
 *
 * gVirtuS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gVirtuS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gVirtuS; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Written by: Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>,
 *             Department of Applied Science
 */

/**
 * @file   Process.cpp
 * @author Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>
 * @date   Wed Sep 30 10:45:40 2009
 *
 * @brief
 *
 *
 */

#include "Process.h"

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

Process::Process(const Communicator *communicator, vector<Handler *> *handlers)
: Subprocess(), Observable() {
    mpCommunicator = const_cast<Communicator *> (communicator);
    mpHandlers = handlers;
}

Process::~Process() {
    cout << "[Process " << GetPid() << "]: Destroyed." << endl;
}

void Process::Setup() {

}

static bool getstring(Communicator *c, string & s) {
    s = "";
    char ch = 0;
    while(c->Read(&ch, 1) == 1) {
        if(ch == 0) {
            return true;
        }
        s += ch;
    }
    return false;
}

void Process::Execute(void * arg) {
    cout << "[Process " << GetPid() << "]: Started." << endl;

    string routine;
    Buffer * input_buffer = new Buffer();
    while (getstring(mpCommunicator, routine)) {
        input_buffer->Reset(mpCommunicator);
        Handler *h = NULL;
        for(vector<Handler *>::iterator i = mpHandlers->begin();
                i != mpHandlers->end(); i++) {
            if((*i)->CanExecute(routine)) {
                h = *i;
                break;
            }
        }
        Result * result;
        if(h == NULL) {
            cout << "[Process " << GetPid() << "]: Requested unknown routine "
                    << routine << "." << endl;
            result = new Result(-1, new Buffer());
        } else
            result = h->Execute(routine, input_buffer);
        result->Dump(mpCommunicator);
        if (result->GetExitCode() != 0) {
            cout << "[Process " << GetPid() << "]: Requested '" << routine
                    << "' routine." << endl;
            cout << "[Process " << GetPid() << "]: Exit Code '"
                    << result->GetExitCode() << "'." << endl;
        }
        delete result;
    }
    delete input_buffer;
    Notify("process-ended");
    delete this;
}

