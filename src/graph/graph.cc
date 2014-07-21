// Copyright (c) 2014, LAAS-CNRS
// Authors: Joseph Mirabel (joseph.mirabel@laas.fr)
//
// This file is part of hpp-manipulation.
// hpp-manipulation is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-manipulation is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-manipulation. If not, see <http://www.gnu.org/licenses/>.

#include "hpp/manipulation/graph/graph.hh"

namespace hpp {
  namespace manipulation {
    namespace graph {
      GraphPtr_t Graph::create(RobotPtr_t robot)
      {
        Graph* ptr = new Graph;
        GraphPtr_t shPtr (ptr);
        ptr->init (shPtr, robot);
        return shPtr;
      }

      void Graph::init (const GraphWkPtr_t& weak, RobotPtr_t robot)
      {
        robot_ = robot;
        wkPtr_ = weak;
      }

      NodeSelectorPtr_t Graph::createNodeSelector()
      {
        NodeSelectorPtr_t newNodeSelector = NodeSelector::create();
        nodeSelectors_.push_back(newNodeSelector);
        return newNodeSelector;
      }
    } // namespace graph
  } // namespace manipulation
} // namespace hpp