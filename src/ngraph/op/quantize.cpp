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

#include "ngraph/op/quantize.hpp"

using namespace std;
using namespace ngraph;

op::Quantize::Quantize(
                shared_ptr<Node> input, 
                shared_ptr<Node> scale, 
                shared_ptr<Node> offset, 
                const element::Type& type,
                const AxisSet& axes)

    : Op("Quantize", check_single_output_args({input, scale, offset}))
    , m_type(type)
    , m_axes(axes)
{
    constructor_validate_and_infer_types();
}

void op::Quantize::validate_and_infer_types()
{
    set_output_size(1);
    set_output_type(0, m_type, get_input_shape(0));
}

shared_ptr<Node> op::Quantize::copy_with_new_args(const NodeVector& new_args) const
{
    check_new_args_count(this, new_args);
    return make_shared<Quantize>(new_args.at(0), new_args.at(1), new_args.at(2), m_type, m_axes);
}

void op::Quantize::generate_adjoints(autodiff::Adjoints& adjoints, const NodeVector& deltas)
{
    // TODO: Error?
}
