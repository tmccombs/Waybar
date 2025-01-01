#pragma once

#include "ALabel.hpp"
#include "modules/sway/ipc/client.hpp"
#include "util/json.hpp"

namespace waybar::modules::sway {

class Mode final : public ALabel {
 public:
  Mode(const std::string&, const Json::Value&);
  virtual ~Mode() = default;
  auto update() -> void override;

 private:
  void onEvent(const struct Ipc::ipc_response&);

  std::string mode_;
  util::JsonParser parser_;
  std::mutex mutex_;
  Ipc ipc_;
};

}  // namespace waybar::modules::sway
