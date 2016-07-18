//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Given Program is inspired from a CodeProject Tutorial, hence follows tutorial's origianal licence
// and credit norms, licence of the original tutorial is included inside hpxflow src/pipeline directory.
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HPXFLOWPIPELINESEGMENT_H
#define HPXFLOWPIPELINESEGMENT_H

#include "HpxFlowPipelineSegmentBase.h"

namespace HpxFlowPipelineProcessing
{
template<class OutputPipeType>
class HpxFlowPipelineSegment : public virtual HpxFlowPipelineProcessing::HpxFlowPipelineSegmentBase
{
protected:

	const static HpxFlowPipelineSegmentBase* const OutputPipeType_Substitutable;
	const static unsigned int OutputPipeType_Not_Void = (unsigned int)sizeof(OutputPipeType);

	//These methods are inherited from the HpxFlowPipelineSegmentBase interface
	virtual bool addOutputHandler(HpxFlowPipelineSegmentBase *output)=0;
	virtual bool removeOutputHandler(HpxFlowPipelineSegmentBase *output)=0;
	virtual bool removeAllOutputHandlers()=0;

public:

	virtual HpxFlowPipelineSegment<OutputPipeType> *connectTo(OutputPipeType *output)=0;
	virtual HpxFlowPipelineSegment<OutputPipeType> *disconnectFrom(OutputPipeType *output)=0;
	virtual void disconnectFromAll()=0;

	virtual void operator+=(OutputPipeType *output)=0;
	virtual void operator-=(OutputPipeType *output)=0;

	virtual void operator+=(OutputPipeType &output)=0;
	virtual void operator-=(OutputPipeType &output)=0;

	virtual ~HpxFlowPipelineSegment() {};
};

template<class OutputPipeType>
const HpxFlowPipelineSegmentBase* const HpxFlowPipelineSegment<OutputPipeType>::OutputPipeType_Substitutable = (const OutputPipeType*) 0;

}

#endif
