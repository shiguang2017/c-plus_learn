#ifndef DASIAMRPNTRACKER_H
#define DASIAMRPNTRACKER_H

#include <torch/script.h>
#include <ATen/ATen.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <Eigen/Dense>

struct TrackerConfig{
// These are the default hyper-params for DaSiamRPN 0.3827
//   Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic,Eigen::RowMajor> window;
   // Params from the network architecture, have to be consistent with the training
   int exemplar_size = 127;  // input z size
   int instance_size = 271;  // input x size (search region)
   int total_stride = 8;
   int score_size = (instance_size-exemplar_size)/total_stride + 1;
   float context_amount = 0.5;  // context amount for the exemplar
//   std::vector<double> w = {0.33,0.5,1,2,3};
//   at::Tensor ratios = at::tensor(w);
   //at::Tensor ratios = at::randn({0.33,0.5,1,2,3}, at::dtype(at::kFloat));
   Eigen::Array<float, 5, 1> ratios;
   Eigen::Array<float, 1, 1> scales;
   at::Tensor window;
//   int scales = 8;
   int anchor_num = 5;
   Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic,Eigen::RowMajor> anchor;
   float penalty_k = 0.04;
   float window_influence = 0.44;
   float lr = 0.45;
};

struct BoxInfo{
    float xc;
    float yc;
    float w;
    float h;
    float best_score;
};

struct TrackInfo{
    int im_h;
    int im_w;
    BoxInfo binfo;
    TrackerConfig cfg;
    cv::Scalar avg_chans;
};

class DaSiamRPNTracker
{
public:
    DaSiamRPNTracker(string mode1,string model2);
    void SiamRPN_init(const cv::Mat& mat, BoxInfo& info);
    void tracker_eval(cv::Mat x_crop,
                      float& scale_z);
    void SiamRPN_track(cv::Mat mat, float& xc, float& yc, float& w, float& h, float& score);
      TrackInfo trackInfo;
       int64 timetotal = 0;

private:

    std::shared_ptr<torch::jit::script::Module> temple_net;
    std::shared_ptr<torch::jit::script::Module> track_net;
    at::Tensor r1_kernel;
    at::Tensor cls_kernel;
    at::Tensor anchor0_tensor;
    at::Tensor anchor1_tensor;
    at::Tensor anchor2_tensor;
    at::Tensor anchor3_tensor;
};





#endif // DASIAMRPNTRACKER_H
