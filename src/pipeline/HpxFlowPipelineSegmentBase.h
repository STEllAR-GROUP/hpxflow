//////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2016 Aalekh Nigam
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Given Program is inspired from a CodeProject Tutorial, hence follows tutorial's origianal licence
// and credit norms, licence of the original tutorial is included inside hpxflow src/pipeline directory.
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HPXFLOWPIPELINESEGMENTBASE
#define IPIPESEGMENTBASE_H
#define HPXFLOWPIPELINESEGMENTBASE
  namespace HpxFlowPipelineProcessing 
{
   class HpxFlowPipelineSegmentBase 
  {
  protected:virtual bool addOutputHandler (HpxFlowPipelineSegmentBase * output) =
      0;
    virtual bool removeOutputHandler (HpxFlowPipelineSegmentBase * output) =
      0;
    virtual bool removeAllOutputHandlers () = 0;
   public: virtual ~ HpxFlowPipelineSegmentBase ()
    {
    };
  };
 }

 
#endif	/*  */
