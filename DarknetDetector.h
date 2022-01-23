# pragma once
// Copyright 2021
//     Use, modification and distribution is subject to the Boost Software
//     License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//     http://www.boost.org/LICENSE_1_0.txt)
//  Authors: 
#include <vector>
#include <string>
#include <memory>
/************************************************************************/
/*      
                                                                        */
/************************************************************************/
struct DetectRect
{
	unsigned int x, y, w, h;       // (x,y) - top-left corner, (w, h) - width & height of bounded box
	float prob;                    // confidence - probability that the object was found correctly
	unsigned int obj_id;           // class of object - from range [0, classes-1]
};

namespace cv { class Mat; }

class DarknetDetector
{
public:
    DarknetDetector();
    ~DarknetDetector();

    bool init(const std::string& cfgFile, const std::string& weightsFile);
    
    void setNMS(double nms);
    double getNMS()const;

    std::vector<DetectRect> detect(const cv::Mat& img, float thresh = 0.2, bool use_mean = false);

private:
    struct Private;
    std::shared_ptr<Private> data;
};
