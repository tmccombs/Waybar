#pragma once

#include <json/value.h>

#include <variant>

using WindowAddress = std::string;

namespace waybar::modules::hyprland {

class Workspaces;

class WindowCreationPayload {
 public:
  WindowCreationPayload(std::string workspace_name, WindowAddress window_address,
                        std::string window_repr);
  WindowCreationPayload(std::string workspace_name, WindowAddress window_address,
                        std::string window_class, std::string window_title);
  WindowCreationPayload(Json::Value const& client_data);

  int incrementTimeSpentUncreated();
  bool isEmpty(Workspaces& workspace_manager);
  bool reprIsReady() const { return std::holds_alternative<Repr>(m_window); }
  std::string repr(Workspaces& workspace_manager);

  std::string getWorkspaceName() const { return m_workspaceName; }
  WindowAddress getAddress() const { return m_windowAddress; }

  void moveToWorksace(std::string& new_workspace_name);

 private:
  void clearAddr();
  void clearWorkspaceName();

  using Repr = std::string;
  using ClassAndTitle = std::pair<std::string, std::string>;
  std::variant<Repr, ClassAndTitle> m_window;

  WindowAddress m_windowAddress;
  std::string m_workspaceName;

  int m_timeSpentUncreated = 0;
};

}  // namespace waybar::modules::hyprland
