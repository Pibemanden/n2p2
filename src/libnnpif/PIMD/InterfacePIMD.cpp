
// n2p2 - A neural network potential package
// Copyright (C) 2018 Andreas Singraber (University of Vienna)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef N2P2_NO_MPI
#include <mpi.h>
#include "mpi-extra.h"
#endif

#include "InterfacePIMD.h"
#include "Atom.h"
#include "Element.h"
#include "utility.h"
#include <cmath>
#include <string>
#include <iostream>
#include <limits>

using namespace nnp;
using namespace std;

void InterfacePIMD::Initialize(int beadRank, const string& filename)
{
    log.writeToStdout = false;
    if(0 == beadRank)
    {
        outputfile = ofstream(filename);
        log.registerStreamPointer(&outputfile);
    }
    else
    {
        log.silent = true;
    }
    Mode::initialize();
    loadSettingsFile("input.nn");
    setupGeneric();
    setupSymmetryFunctionScaling("scaling.data");
    bool collectStatistics = false;
    bool collectExtrapolationWarnings = false;
    bool writeExtrapolationWarnings = false;
    bool stopOnExtrapolationWarnings = false;
//    if (showew == true || showewsum > 0 || maxew >= 0)
    {
        collectExtrapolationWarnings = true;
    }
    setupSymmetryFunctionStatistics(collectStatistics,
                                    collectExtrapolationWarnings,
                                    writeExtrapolationWarnings,
                                    stopOnExtrapolationWarnings);
    setupNeuralNetworkWeights("weights.%03d.data");

}