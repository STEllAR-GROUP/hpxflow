//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Given Program is inspired from a CodeProject Tutorial, hence follows tutorial's origianal licence
// and credit norms, licence of the original tutorial is included inside hpxflow src/pipeline directory.
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PIPELINESEGMENT_H
#define PIPELINESEGMENT_H

#include <vector>

#include "HpxFlowPipelineSegment.h"

namespace HpxFlowPipelineProcessing
{

template<class OutputPipeType>
class HpxFlowPipeSegment : public HpxFlowPipelineProcessing::HpxFlowPipelineSegment<OutputPipeType>
{

protected:

	const static HpxFlowPipelineSegmentBase* const OutputPipeType_Substitutable;
	const static unsigned int OutputPipeType_Not_Void = (unsigned int)sizeof(OutputPipeType);
	std::vector<HpxFlowPipelineSegmentBase *> theOutput;

	virtual bool addOutputHandler(HpxFlowPipelineSegmentBase *output)
		{ if (!(output)|| output == this) return false;
		  // hpx::parallel::for_each(
				// 		        hpx::parallel::par,
				// 		        std::begin(theOutput), std::end(theOutput),
				// 		        [&](HpxFlowPipelineSegmentBase * element) {
				// 		        	if(theOutput[i] == output) return true;
		  // });

			for (auto const &element : theOutput) {
				if(element == output) return true;
			}
		  theOutput.push_back(output);
		  return true;	//The output handler has been added.
		};

	virtual bool removeOutputHandler(HpxFlowPipelineSegmentBase *output)
		{

		  for (auto &element : theOutput) {
				if (element == output) {
						//theOutput.erase(element);
						return true;
				}
		  }

		  return true;
		};

	virtual bool removeAllOutputHandlers()
		{ theOutput.clear();
		  return true;
		};

public:
	HpxFlowPipeSegment() {};

	virtual HpxFlowPipeSegment<OutputPipeType> *connectTo(OutputPipeType *output)
		{ addOutputHandler(output); return this; };

	virtual HpxFlowPipeSegment<OutputPipeType> *disconnectFrom(OutputPipeType *output)
		{ removeOutputHandler(output); return this; };

	virtual void disconnectFromAll()
		{ removeAllOutputHandlers(); };

	virtual void operator+=(OutputPipeType *output)
		{ addOutputHandler(output); };

	virtual void operator-=(OutputPipeType *output)
		{ removeOutputHandler(output); };

	virtual void operator+=(OutputPipeType &output)
		{ addOutputHandler(&output); };

	virtual void operator-=(OutputPipeType &output)
		{ removeOutputHandler(&output); };

	virtual ~HpxFlowPipeSegment() {};
};

// template<class OutputPipeType>
// const HpxFlowPipelineSegmentBase*;
// const PipelineSegment<OutputPipeType>::OutputPipeType_Substitutable = (const OutputPipeType*) 0;


}

#endif
