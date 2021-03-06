//*****************************************************************************
// Copyright 2017-2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#include "ngraph/op/stop_gradient.hpp"
#include "ngraph/op/broadcast.hpp"
#include "ngraph/op/constant.hpp"

using namespace std;
using namespace ngraph;

op::StopGradient::StopGradient(const shared_ptr<Node>& arg)
    : UnaryElementwiseArithmetic("StopGradient", arg)
{
    constructor_validate_and_infer_types();
}

shared_ptr<Node> op::StopGradient::copy_with_new_args(const NodeVector& new_args) const
{
    check_new_args_count(this, new_args);
    return make_shared<StopGradient>(new_args.at(0));
}
