#pragma once

#include <core/ModelInterpretor.h>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"

namespace naivebayes {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class NaiveBayesApp : public ci::app::App {
 public:
  std::ifstream saved_model = std::ifstream(
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "models/test_validation_model");

  ModelInterpretor m = ModelInterpretor(saved_model);

  NaiveBayesApp();

  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  // TODO: Delete this comment. Feel free to play around with these variables
  // provided that you can see the entire UI on your screen.
  const double kWindowSize = 600;
  const double kMargin = 100;
  const size_t kImageDimension = 28;

 private:
  Sketchpad sketchpad_;
  int current_prediction_ = -1;
};

}  // namespace visualizer

}  // namespace naivebayes
