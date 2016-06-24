////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#ifndef HPXFLOWPIPELINESEGMENTBASEADAPTER_H
#define HPXFLOWPIPELINESEGMENTBASEADAPTER_H

#include "HpxFlowPipelineSegmentBase.h"

namespace HpxFlowPipelineProcessing
{

class HpxFlowPipelineSegmentBaseAdapter : public HpxFlowPipelineProcessing::HpxFlowPipelineSegmentBase
{
protected:
	HpxFlowPipelineSegmentBaseAdapter() {};

	virtual bool addOutputHandler(HpxFlowPipelineSegmentBase *output) { return true; };
	virtual bool removeOutputHandler(HpxFlowPipelineSegmentBase *output) { return true; };
	virtual bool removeAllOutputHandlers() { return true; };

public:

	virtual ~HpxFlowPipelineSegmentBaseAdapter() {};
};

}

#endif
