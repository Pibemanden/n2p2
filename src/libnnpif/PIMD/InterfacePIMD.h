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

#ifndef INTERFACEPIMD_H
#define INTERFACEPIMD_H

#include "Mode.h"
#include "Structure.h"
#include <map>     // std::map
#include <cstddef> // std::size_t
#include <cstdint> // int64_t
#include <string>  // std::string

namespace nnp
{

class InterfacePIMD : public Mode
{
public:
InterfacePIMD() : outputfile(NULL) {};
~InterfacePIMD() {};

void Initialize(int, const std::string&);


/** Add one neighbor to atom
 *
 * @param[in] i Local atom index.
 * @param[in] j Neighbor atom index.
 * @param[in] tag Neighbor atom tag.
 * @param[in] type Neighbor atom type.
 * @param[in] dx Neighbor atom distance in x direction.
 * @param[in] dy Neighbor atom distance in y direction.
 * @param[in] dz Neighbor atom distance in z direction.
 * @param[in] d2 Square of neighbor atom distance.
 *
 */
void   addNeighbor(int     i,
                   int     j,
                   int64_t tag,
                   int     type,
                   double  dx,
                   double  dy,
                   double  dz,
                   double  d2) {};

protected:
/// Structure containing local atoms.
Structure                  structure;
std::ofstream              outputfile;

};

}

#endif // INTERFACEPIMD_H