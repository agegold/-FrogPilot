#include "selfdrive/frogpilot/ui/control_settings.h"

FrogPilotControlsPanel::FrogPilotControlsPanel(SettingsWindow *parent) : FrogPilotListWidget(parent) {
  const std::vector<std::tuple<QString, QString, QString, QString>> controlToggles {
    {"AdjustablePersonalities", "Adjustable Personalities", "Use the 'Distance' button on the steering wheel or the onroad UI to switch between openpilot's driving personalities.\n\n1 bar = Aggressive\n2 bars = Standard\n3 bars = Relaxed", "../frogpilot/assets/toggle_icons/icon_distance.png"},

    {"AlwaysOnLateral", "상시 핸들 조향", "브레이크 또는 가속 페달을 사용할때 오픈파일럿은 항상 핸들 조향을 합니다.\n\n핸들조향을 끌때는 크루즈 버튼을 사용하세요.", "../frogpilot/assets/toggle_icons/icon_always_on_lateral.png"},
    {"AlwaysOnLateralMain", "크루즈 컨트롤 사용", "크루즈 컨트롤 키면 항상 핸들조향이 됩니다.", ""},
    {"HideAOLStatusBar", "상태 표시줄 숨기기", "상시 핸들 조향시 상태바를 사용 사용하지 마세요.", ""},

    {"ConditionalExperimental", "조건부 실험 모드", "미리 정의된 조건에 따라 자동으로 '실험 모드'로 전환 됩니다.", "../frogpilot/assets/toggle_icons/icon_conditional.png"},
    {"CECurves", "전방에 커브 감지됨", "커브가 감지되면 '실험 모드'로 전환됩니다.", ""},
    {"CENavigation", "네비게이션 기반", "내비게이션 데이터(예: 교차로, 정지 신호 등)를 기반으로 '실험 모드'로 전환합니다.", ""},
    {"CESlowerLead", "전방에 느린 선행차 감지", "앞서 느린 선두 차량이 감지되면 '실험 모드'로 전환합니다.", ""},
    {"CEStopLights", "정지 신호등 및 정지 신호", "정지등이나 정지 신호가 감지되면 '실험 모드'로 전환합니다.", ""},
    {"CESignal", "고속도로 속도 이하일때 방향 지시등", "회전을 보조하기 위해 고속도로 속도 이하에서 방향 지시등을 사용할 때 '실험 모드'로 전환하세요.", ""},
    {"HideCEMStatusBar", "상태 표시줄 숨기기", "조건부 실험 모드에서 상태바를 사용하지 마세요'.", ""},

    {"CustomPersonalities", "사용자 정의 운전 성격", "운전 성격 프로필을 운전 스타일에 맞게 사용자 정의하세요.", "../frogpilot/assets/toggle_icons/icon_custom.png"},
    {"DeviceShutdown", "장치 종료 타이머", "오프로드 시 에너지를 절약하고 배터리 소모를 방지할 때 자동 장치 종료를 위한 타이머를 구성합니다.", "../frogpilot/assets/toggle_icons/icon_time.png"},

    {"ExperimentalModeActivation", "실험 모드 활성화", "운전대 또는 화면의 버튼을 사용하여 실험 모드를 전환합니다.\n\n'조건부 실험 모드'를 재정의합니다.'.", "../assets/img_experimental_white.svg"},
    {"ExperimentalModeViaLKAS", "LKAS 버튼을 두 번 클릭", "핸들에 있는 'LKAS' 버튼을 두 번 클릭하여 '실험 모드'를 활성화/비활성화합니다.", ""},
    {"ExperimentalModeViaScreen", "Onroad UI를 두 번 탭하기", "0.5초 내에 Onroad UI를 두 번 탭하여 '실험 모드'를 활성화/비활성화합니다.", ""},
    {"ExperimentalModeViaDistance", "거리 버튼을 길게 누르기", "핸들에 있는 '거리' 버튼을 0.5초 동안 눌러 '실험 모드'를 활성화/비활성화합니다.", ""},

    {"FireTheBabysitter", "베이비시터 정지", "더 많은 사용자 자율성을 위해 openpilot의 '베이비시터' 프로토콜 중 일부를 비활성화합니다.", "../frogpilot/assets/toggle_icons/icon_babysitter.png"},
    {"MuteOverheated", "열 안전 제한 우회", "오픈파일럿에서 표시된 권장 열 제한을 초과하는 온도에서도 장치가 작동하도록 허용합니다.", ""},
    {"NoLogging", "로깅 비활성화", "개인 정보 보호를 강화하거나 열 부하를 줄이려면 모든 데이터 추적을 끄십시오.\n\n경고: 이 조치는 드라이브 기록을 방지하며 데이터를 복구할 수 없습니다!", ""},
    {"NoUploads", "업로드 비활성화", "서버에 대한 모든 데이터 업로드를 끄십시오.\n\n경고: 이 작업을 수행하면 드라이브가 디버깅 및 지원에 영향을 줄 수 있는 쉼표 연결에 표시되는 것을 방지할 수 있습니다!", ""},
    {"OfflineMode", "오프라인 모드", "기기를 무기한으로 오프라인 상태로 유지합니다.", ""},

    {"LateralTune", "핸들 조향 튜닝", "openpilot의 조종 동작을 수정합니다.", "../frogpilot/assets/toggle_icons/icon_lateral_tune.png"},
    {"ForceAutoTune", "강제 자동 튜닝", "지원되지 않는 차량에 대해 쉼표로 자동 측면 튜닝을 강제합니다.", ""},
    {"NNFF", "NNFF - Neural Network Feedforward", "측면 제어의 정확성을 높이려면 Twilsonco의 신경망 피드포워드를 사용하십시오.", ""},
    {"SteerRatio", steerRatioStock != 0 ? QString("Steer Ratio (Default: %1)").arg(steerRatioStock, 0, 'f', 2) : "Steer Ratio", "차량 컨트롤에 대한 사용자 정의 스티어링 비율을 설정합니다.", ""},
    {"UseLateralJerk", "측면 저크 사용", "원하는 조향 속도(측면 저크)를 달성하는 데 필요한 조향 토크를 포함합니다.", ""},

    {"LongitudinalTune", "가감속 튜닝", "openpilot의 가속 및 제동 동작을 수정합니다.", "../frogpilot/assets/toggle_icons/icon_longitudinal_tune.png"},
    {"AccelerationProfile", "가속 프로필", "가속률을 스포티하거나 친환경적으로 변경하세요.", ""},
    {"DecelerationProfile", "감속 프로필", "감속률을 스포티하거나 친환경적으로 변경하세요.", ""},
    {"AggressiveAcceleration", "선행차를 사용한 공격적인 가속", "차 후 선두 차량을 따라갈 때 가속도를 높입니다.", ""},
    {"StoppingDistance", "선행 차량 뒤의 정지 거리 증가", "선행 차량으로부터 보다 편안한 정지를 위해 정지 거리를 증가시킵니다.", ""},
    {"LeadDetectionThreshold", "선행 차량 감지 임계값", "선행 차량 감지 임계값을 늘리거나 줄여 리드를 더 빨리 감지하거나 모델 신뢰도를 높이세요.", ""},
    {"SmoothBraking", "선행 차량후의 부드러운 제동", "저속 차량에 접근할 때 제동 동작을 부드럽게 합니다.", ""},
    {"TrafficMode", "교통정체 모드", "거리' 버튼을 2.5초 동안 누르고 있으면 교통 정체 및 정체에 맞춰 보다 공격적인 운전 행동을 활성화할 수 있습니다.", ""},

    {"Model", "Model Selector", "Choose your preferred openpilot model.", "../assets/offroad/icon_calibration.png"},

    {"MTSCEnabled", "Map Turn Speed Control", "Slow down for anticipated curves detected by your downloaded maps.", "../frogpilot/assets/toggle_icons/icon_speed_map.png"},
    {"DisableMTSCSmoothing", "Disable MTSC UI Smoothing", "Disables the smoothing for the requested speed in the onroad UI.", ""},
    {"MTSCCurvatureCheck", "Model Curvature Detection Failsafe", "Only trigger MTSC when the model detects a curve in the road. Purely used as a failsafe to prevent false positives. Leave this off if you never experience false positives.", ""},
    {"MTSCLimit", "Speed Change Hard Cap", "Set a hard cap for MTSC. If MTSC requests a speed decrease greater than this value, it ignores the requested speed from MTSC. Purely used as a failsafe to prevent false positives. Leave this off if you never experience false positives.", ""},
    {"MTSCAggressiveness", "Turn Speed Aggressiveness", "Set turn speed aggressiveness. Higher values result in faster turns, lower values yield gentler turns.\n\nA change of +- 1% results in the velocity being raised or lowered by about 1 mph.", ""},

    {"NudgelessLaneChange", "Nudgeless Lane Change", "Enable lane changes without manual steering input.", "../frogpilot/assets/toggle_icons/icon_lane.png"},
    {"LaneChangeTime", "Lane Change Timer", "Specify a delay before executing a nudgeless lane change.", ""},
    {"LaneDetection", "Lane Detection", "Block nudgeless lane changes when a lane isn't detected.", ""},
    {"LaneDetectionWidth", "Lane Detection Threshold", "Set the required lane width to be qualified as a lane.", ""},
    {"OneLaneChange", "One Lane Change Per Signal", "Limit to one nudgeless lane change per turn signal activation.", ""},

    {"QOLControls", "Quality of Life", "Miscellaneous quality of life changes to improve your overall openpilot experience.", "../frogpilot/assets/toggle_icons/quality_of_life.png"},
    {"DisableOnroadUploads", "Disable Onroad Uploads", "Prevent large data uploads when onroad.", ""},
    {"HigherBitrate", "Higher Bitrate Recording", "Increases the quality of the footage uploaded to comma connect.", ""},
    {"NavChill", "Navigate on Chill Mode", "Allows cars without longitudinal support to navigate. Allows navigation without experimental mode.", ""},
    {"PauseLateralOnSignal", "Pause Lateral On Turn Signal Below", "Temporarily disable lateral control during turn signal use below the set speed.", ""},
    {"ReverseCruise", "Reverse Cruise Increase", "Reverses the 'long press' functionality when increasing the max set speed. Useful to increase the max speed quickly.", ""},
    {"SetSpeedOffset", "Set Speed Offset", "Set an offset for your desired set speed.", ""},

    {"SpeedLimitController", "Speed Limit Controller", "Automatically adjust vehicle speed to match speed limits using 'Open Street Map's, 'Navigate On openpilot', or your car's dashboard (TSS2 Toyotas only).", "../assets/offroad/icon_speed_limit.png"},
    {"SLCControls", "Controls Settings", "Manage settings for the controls.", ""},
    {"Offset1", "Speed Limit Offset (0-34 mph)", "Speed limit offset for speed limits between 0-34 mph.", ""},
    {"Offset2", "Speed Limit Offset (35-54 mph)", "Speed limit offset for speed limits between 35-54 mph.", ""},
    {"Offset3", "Speed Limit Offset (55-64 mph)", "Speed limit offset for speed limits between 55-64 mph.", ""},
    {"Offset4", "Speed Limit Offset (65-99 mph)", "Speed limit offset for speed limits between 65-99 mph.", ""},
    {"SLCFallback", "Fallback Method", "Choose your fallback method for when there are no speed limits currently being obtained from Navigation, OSM, and the car's dashboard.", ""},
    {"SLCOverride", "Override Method", "Choose your preferred method to override the current speed limit.", ""},
    {"SLCPriority", "Priority Order", "Determine the priority order for what speed limits to use.", ""},
    {"SLCQOL", "Quality of Life Settings", "Manage quality of life settings.", ""},
    {"SLCConfirmation", "Confirm New Speed Limits", "Don't automatically start using the new speed limit until it's been manually confirmed first.", ""},
    {"ForceMPHDashboard", "Force MPH From Dashboard Readings", "Force MPH readings from the dashboard. Only use this if you live in an area where the speed limits from your dashboard are in KPH but you use MPH.", ""},
    {"SetSpeedLimit", "Use Current Speed Limit As Set Speed", "Sets your max speed to the current speed limit if one is populated when you initially enable openpilot.", ""},
    {"SLCVisuals", "Visuals Settings", "Manage visual settings.", ""},
    {"ShowSLCOffset", "Show Speed Limit Offset", "Show the speed limit offset seperated from the speed limit in the onroad UI when using 'Speed Limit Controller'.", ""},
    {"UseVienna", "Use Vienna Speed Limit Signs", "Use the Vienna (EU) speed limit style signs as opposed to MUTCD (US).", ""},

    {"TurnDesires", "Use Turn Desires", "Use turn desires for enhanced precision in turns below the minimum lane change speed.", "../assets/navigation/direction_continue_right.png"},

    {"VisionTurnControl", "Vision Turn Speed Controller", "Slow down for detected road curvature for smoother curve handling.", "../frogpilot/assets/toggle_icons/icon_vtc.png"},
    {"DisableVTSCSmoothing", "Disable VTSC UI Smoothing", "Disables the smoothing for the requested speed in the onroad UI.", ""},
    {"CurveSensitivity", "Curve Detection Sensitivity", "Set curve detection sensitivity. Higher values prompt earlier responses, lower values lead to smoother but later reactions.", ""},
    {"TurnAggressiveness", "Turn Speed Aggressiveness", "Set turn speed aggressiveness. Higher values result in faster turns, lower values yield gentler turns.", ""},
  };

  for (const auto &[param, title, desc, icon] : controlToggles) {
    ParamControl *toggle;

    if (param == "AdjustablePersonalities") {
      std::vector<QString> adjustablePersonalitiesToggles{"PersonalitiesViaWheel", "PersonalitiesViaScreen"};
      std::vector<QString> adjustablePersonalitiesNames{tr("Distance Button"), tr("Screen")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, adjustablePersonalitiesToggles, adjustablePersonalitiesNames);

    } else if (param == "AlwaysOnLateral") {
      FrogPilotParamManageControl *aolToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(aolToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(aolKeys.find(key.c_str()) != aolKeys.end());
        }
      });
      toggle = aolToggle;

    } else if (param == "ConditionalExperimental") {
      FrogPilotParamManageControl *conditionalExperimentalToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(conditionalExperimentalToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        conditionalSpeedsImperial->setVisible(!isMetric);
        conditionalSpeedsMetric->setVisible(isMetric);
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(conditionalExperimentalKeys.find(key.c_str()) != conditionalExperimentalKeys.end());
        }
      });
      toggle = conditionalExperimentalToggle;
    } else if (param == "CECurves") {
      FrogPilotParamValueControl *CESpeedImperial = new FrogPilotParamValueControl("CESpeed", "Below", "Switch to 'Experimental Mode' below this speed in absence of a lead vehicle.", "", 0, 99,
                                                                                   std::map<int, QString>(), this, false, " mph");
      FrogPilotParamValueControl *CESpeedLeadImperial = new FrogPilotParamValueControl("CESpeedLead", "  w/Lead", "Switch to 'Experimental Mode' below this speed when following a lead vehicle.", "", 0, 99,
                                                                                       std::map<int, QString>(), this, false, " mph");
      conditionalSpeedsImperial = new FrogPilotDualParamControl(CESpeedImperial, CESpeedLeadImperial, this);
      addItem(conditionalSpeedsImperial);

      FrogPilotParamValueControl *CESpeedMetric = new FrogPilotParamValueControl("CESpeed", "Below", "Switch to 'Experimental Mode' below this speed in absence of a lead vehicle.", "", 0, 150,
                                                                                 std::map<int, QString>(), this, false, " kph");
      FrogPilotParamValueControl *CESpeedLeadMetric = new FrogPilotParamValueControl("CESpeedLead", "  w/Lead", "Switch to 'Experimental Mode' below this speed when following a lead vehicle.", "", 0, 150,
                                                                                     std::map<int, QString>(), this, false, " kph");
      conditionalSpeedsMetric = new FrogPilotDualParamControl(CESpeedMetric, CESpeedLeadMetric, this);
      addItem(conditionalSpeedsMetric);

      std::vector<QString> curveToggles{"CECurvesLead"};
      std::vector<QString> curveToggleNames{tr("With Lead")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, curveToggles, curveToggleNames);
    } else if (param == "CENavigation") {
      std::vector<QString> navigationToggles{"CENavigationIntersections", "CENavigationTurns", "CENavigationLead"};
      std::vector<QString> navigationToggleNames{tr("Intersections"), tr("Turns"), tr("With Lead")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, navigationToggles, navigationToggleNames);
    } else if (param == "CEStopLights") {
      std::vector<QString> stopLightToggles{"CEStopLightsLead"};
      std::vector<QString> stopLightToggleNames{tr("With Lead")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, stopLightToggles, stopLightToggleNames);

    } else if (param == "CustomPersonalities") {
      FrogPilotParamManageControl *customPersonalitiesToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(customPersonalitiesToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(false);
        }
        aggressiveProfile->setVisible(true);
        standardProfile->setVisible(true);
        relaxedProfile->setVisible(true);
      });
      toggle = customPersonalitiesToggle;

      FrogPilotParamValueControl *aggressiveFollow = new FrogPilotParamValueControl("AggressiveFollow", "Follow",
                                                                                    "Set the 'Aggressive' personality' following distance. "
                                                                                    "Represents seconds to follow behind the lead vehicle.\n\nStock: 1.25 seconds.",
                                                                                    "../frogpilot/assets/other_images/aggressive.png",
                                                                                    1, 5, std::map<int, QString>(), this, false, " sec", 1, 0.01);
      FrogPilotParamValueControl *aggressiveJerk = new FrogPilotParamValueControl("AggressiveJerk", " Jerk",
                                                                                  "Configure brake/gas pedal responsiveness for the 'Aggressive' personality. "
                                                                                  "Higher jerk value = smoother rides.\nLower jerk value = faster response.\n\nStock: 0.5.",
                                                                                  "",
                                                                                  0.01, 5, std::map<int, QString>(), this, false, "", 1, 0.01);
      aggressiveProfile = new FrogPilotDualParamControl(aggressiveFollow, aggressiveJerk, this, true);
      addItem(aggressiveProfile);

      FrogPilotParamValueControl *standardFollow = new FrogPilotParamValueControl("StandardFollow", "Follow",
                                                                                  "Set the 'Standard' personality following distance. "
                                                                                  "Represents seconds to follow behind the lead vehicle.\n\nStock: 1.45 seconds.",
                                                                                  "../frogpilot/assets/other_images/standard.png",
                                                                                  1, 5, std::map<int, QString>(), this, false, " sec", 1, 0.01);
      FrogPilotParamValueControl *standardJerk = new FrogPilotParamValueControl("StandardJerk", " Jerk",
                                                                                "Adjust brake/gas pedal responsiveness for the 'Standard' personality. "
                                                                                "Higher jerk value = smoother rides.\nLower jerk value = faster response.\n\nStock: 1.0.",
                                                                                "",
                                                                                0.01, 5, std::map<int, QString>(), this, false, "", 1, 0.01);
      standardProfile = new FrogPilotDualParamControl(standardFollow, standardJerk, this, true);
      addItem(standardProfile);

      FrogPilotParamValueControl *relaxedFollow = new FrogPilotParamValueControl("RelaxedFollow", "Follow",
                                                                                 "Set the 'Relaxed' personality following distance. "
                                                                                 "Represents seconds to follow behind the lead vehicle.\n\nStock: 1.75 seconds.",
                                                                                 "../frogpilot/assets/other_images/relaxed.png",
                                                                                 1, 5, std::map<int, QString>(), this, false, " sec", 1, 0.01);
      FrogPilotParamValueControl *relaxedJerk = new FrogPilotParamValueControl("RelaxedJerk", " Jerk",
                                                                               "Set brake/gas pedal responsiveness for the 'Relaxed' personality. "
                                                                               "Higher jerk value = smoother rides.\nLower jerk value = faster response.\n\nStock: 1.0.",
                                                                               "",
                                                                               0.01, 5, std::map<int, QString>(), this, false, "", 1, 0.01);
      relaxedProfile = new FrogPilotDualParamControl(relaxedFollow, relaxedJerk, this, true);
      addItem(relaxedProfile);

    } else if (param == "DeviceShutdown") {
      std::map<int, QString> shutdownLabels;
      for (int i = 0; i <= 33; ++i) {
        shutdownLabels[i] = i == 0 ? "Instant" : i <= 3 ? QString::number(i * 15) + " mins" : QString::number(i - 3) + (i == 4 ? " hour" : " hours");
      }
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 33, shutdownLabels, this, false);

    } else if (param == "ExperimentalModeActivation") {
      FrogPilotParamManageControl *experimentalModeActivationToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(experimentalModeActivationToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(experimentalModeActivationKeys.find(key.c_str()) != experimentalModeActivationKeys.end());
        }
      });
      toggle = experimentalModeActivationToggle;

    } else if (param == "FireTheBabysitter") {
      FrogPilotParamManageControl *fireTheBabysitterToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(fireTheBabysitterToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(fireTheBabysitterKeys.find(key.c_str()) != fireTheBabysitterKeys.end());
        }
      });
      toggle = fireTheBabysitterToggle;

    } else if (param == "LateralTune") {
      FrogPilotParamManageControl *lateralTuneToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(lateralTuneToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(lateralTuneKeys.find(key.c_str()) != lateralTuneKeys.end());
        }
      });
      toggle = lateralTuneToggle;
    } else if (param == "SteerRatio") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, steerRatioStock * 0.75, steerRatioStock * 1.25, std::map<int, QString>(), this, false, "", 1, 0.01);

    } else if (param == "LongitudinalTune") {
      FrogPilotParamManageControl *longitudinalTuneToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(longitudinalTuneToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(longitudinalTuneKeys.find(key.c_str()) != longitudinalTuneKeys.end());
        }
      });
      toggle = longitudinalTuneToggle;
    } else if (param == "AccelerationProfile") {
      std::vector<QString> profileOptions{tr("Standard"), tr("Eco"), tr("Sport"), tr("Sport+")};
      FrogPilotButtonParamControl *profileSelection = new FrogPilotButtonParamControl(param, title, desc, icon, profileOptions);
      toggle = profileSelection;

      QObject::connect(static_cast<FrogPilotButtonParamControl*>(toggle), &FrogPilotButtonParamControl::buttonClicked, [this](int id) {
        if (id == 3) {
          FrogPilotConfirmationDialog::toggleAlert("WARNING: This maxes out openpilot's acceleration from 2.0 m/s to 4.0 m/s and may cause oscillations when accelerating!",
          "I understand the risks.", this);
        }
      });
    } else if (param == "DecelerationProfile") {
      std::vector<QString> profileOptions{tr("Standard"), tr("Eco"), tr("Sport")};
      FrogPilotButtonParamControl *profileSelection = new FrogPilotButtonParamControl(param, title, desc, icon, profileOptions);
      toggle = profileSelection;
    } else if (param == "StoppingDistance") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 10, std::map<int, QString>(), this, false, " feet");
    } else if (param == "LeadDetectionThreshold") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 1, 100, std::map<int, QString>(), this, false, "%");

    } else if (param == "Model") {
      modelSelectorButton = new FrogPilotButtonIconControl(title, tr("SELECT"), desc, icon);
      QStringList models = {"los-angeles", "certified-herbalist", "duck-amigo", "recertified-herbalist"};
      QStringList modelLabels = {"Los Angeles (Default)", "Certified Herbalist", "Duck Amigo", "Recertified Herbalist"};
      QObject::connect(modelSelectorButton, &FrogPilotButtonIconControl::clicked, this, [this, models, modelLabels]() {
        QString selection = MultiOptionDialog::getSelection(tr("Select a driving model"), modelLabels, "", this);

        if (!selection.isEmpty()) {
          int selectedModelIndex = modelLabels.indexOf(selection);
          QString selectedModelValue = models[selectedModelIndex];
          params.put("Model", selectedModelValue.toStdString());
          modelSelectorButton->setValue(selection);
          if (FrogPilotConfirmationDialog::yesorno("Do you want to start with a fresh calibration for the newly selected model?", this)) {
            params.remove("CalibrationParams");
            params.remove("LiveTorqueParameters");
          }
          if (started) {
            if (FrogPilotConfirmationDialog::toggle("Reboot required to take effect.", "Reboot Now", this)) {
              Hardware::soft_reboot();
            }
          }
        }
      });
      int initialModelIndex = models.indexOf(QString::fromStdString(params.get("Model")));
      QString initialModelLabel = modelLabels[initialModelIndex];
      modelSelectorButton->setValue(initialModelLabel);
      addItem(modelSelectorButton);

    } else if (param == "MTSCEnabled") {
      FrogPilotParamManageControl *mtscToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(mtscToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(mtscKeys.find(key.c_str()) != mtscKeys.end());
        }
      });
      toggle = mtscToggle;
    } else if (param == "MTSCAggressiveness") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 1, 200, std::map<int, QString>(), this, false, "%");
    } else if (param == "MTSCLimit") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 99, std::map<int, QString>(), this, false, " mph");

    } else if (param == "QOLControls") {
      FrogPilotParamManageControl *qolToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(qolToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(qolKeys.find(key.c_str()) != qolKeys.end());
        }
      });
      toggle = qolToggle;
    } else if (param == "PauseLateralOnSignal") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 99, std::map<int, QString>(), this, false, " mph");
    } else if (param == "ReverseCruise") {
      std::vector<QString> reverseCruiseToggles{"ReverseCruiseUI"};
      std::vector<QString> reverseCruiseNames{tr("Control Via UI")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, reverseCruiseToggles, reverseCruiseNames);
    } else if (param == "SetSpeedOffset") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 99, std::map<int, QString>(), this, false, " mph");

    } else if (param == "NudgelessLaneChange") {
      FrogPilotParamManageControl *laneChangeToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(laneChangeToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(laneChangeKeys.find(key.c_str()) != laneChangeKeys.end());
        }
      });
      toggle = laneChangeToggle;
    } else if (param == "LaneChangeTime") {
      std::map<int, QString> laneChangeTimeLabels;
      for (int i = 0; i <= 10; ++i) {
        laneChangeTimeLabels[i] = i == 0 ? "Instant" : QString::number(i / 2.0) + " seconds";
      }
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 10, laneChangeTimeLabels, this, false);
    } else if (param == "LaneDetectionWidth") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 100, std::map<int, QString>(), this, false, " feet", 10);

    } else if (param == "SpeedLimitController") {
      FrogPilotParamManageControl *speedLimitControllerToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(speedLimitControllerToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(speedLimitControllerKeys.find(key.c_str()) != speedLimitControllerKeys.end());
        }
      });
      toggle = speedLimitControllerToggle;
    } else if (param == "SLCControls") {
      FrogPilotParamManageControl *manageSLCControlsToggle = new FrogPilotParamManageControl(param, title, desc, icon, this, true);
      QObject::connect(manageSLCControlsToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(speedLimitControllerControlsKeys.find(key.c_str()) != speedLimitControllerControlsKeys.end());
          subParentToggleClicked();
        }
        slcPriorityButton->setVisible(true);
      });
      toggle = manageSLCControlsToggle;
    } else if (param == "SLCQOL") {
      FrogPilotParamManageControl *manageSLCQOLToggle = new FrogPilotParamManageControl(param, title, desc, icon, this, true);
      QObject::connect(manageSLCQOLToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(speedLimitControllerQOLKeys.find(key.c_str()) != speedLimitControllerQOLKeys.end());
          subParentToggleClicked();
        }
      });
      toggle = manageSLCQOLToggle;
    } else if (param == "SLCConfirmation") {
      std::vector<QString> slcConfirmationToggles{"SLCConfirmationLower", "SLCConfirmationHigher"};
      std::vector<QString> slcConfirmationNames{tr("Lower Limits"), tr("Higher Limits")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, slcConfirmationToggles, slcConfirmationNames);
    } else if (param == "SLCVisuals") {
      FrogPilotParamManageControl *manageSLCVisualsToggle = new FrogPilotParamManageControl(param, title, desc, icon, this, true);
      QObject::connect(manageSLCVisualsToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(speedLimitControllerVisualsKeys.find(key.c_str()) != speedLimitControllerVisualsKeys.end());
          subParentToggleClicked();
        }
      });
      toggle = manageSLCVisualsToggle;
    } else if (param == "Offset1" || param == "Offset2" || param == "Offset3" || param == "Offset4") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, -99, 99, std::map<int, QString>(), this, false, " mph");
    } else if (param == "ShowSLCOffset") {
      std::vector<QString> slcOffsetToggles{"ShowSLCOffsetUI"};
      std::vector<QString> slcOffsetToggleNames{tr("Control Via UI")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, slcOffsetToggles, slcOffsetToggleNames);
    } else if (param == "SLCFallback") {
      std::vector<QString> fallbackOptions{tr("Set Speed"), tr("Experimental Mode"), tr("Previous Limit")};
      FrogPilotButtonParamControl *fallbackSelection = new FrogPilotButtonParamControl(param, title, desc, icon, fallbackOptions);
      toggle = fallbackSelection;
    } else if (param == "SLCOverride") {
      std::vector<QString> overrideOptions{tr("None"), tr("Manual Set Speed"), tr("Set Speed")};
      FrogPilotButtonParamControl *overrideSelection = new FrogPilotButtonParamControl(param, title, desc, icon, overrideOptions);
      toggle = overrideSelection;
    } else if (param == "SLCPriority") {
      slcPriorityButton = new ButtonControl(title, tr("SELECT"), desc);
      QStringList primaryPriorities = {"None", "Dashboard", "Navigation", "Offline Maps", "Highest", "Lowest"};
      QStringList secondaryTertiaryPriorities = {"None", "Dashboard", "Navigation", "Offline Maps"};
      QStringList priorityPrompts = {tr("Select your primary priority"), tr("Select your secondary priority"), tr("Select your tertiary priority")};

      QObject::connect(slcPriorityButton, &ButtonControl::clicked, this, [this, primaryPriorities, secondaryTertiaryPriorities, priorityPrompts]() {
        QStringList availablePriorities = primaryPriorities;
        QStringList selectedPriorities;
        for (int i = 1; i <= 3; ++i) {
          QStringList currentPriorities = (i == 1) ? availablePriorities : secondaryTertiaryPriorities;

          for (const QString &selectedPriority : selectedPriorities) {
            currentPriorities.removeAll(selectedPriority);
          }

          QString priorityKey = QString("SLCPriority%1").arg(i);
          QString selection = MultiOptionDialog::getSelection(priorityPrompts[i - 1], currentPriorities, "", this);
          if (!selection.isEmpty()) {
            params.put(priorityKey.toStdString(), selection.toStdString());
            selectedPriorities.append(selection);

            if (i == 1 && (selection == "Highest" || selection == "Lowest" || selection == "None")) {
              for (int j = i + 1; j <= 3; ++j) {
                QString remainingPriorityKeys = QString("SLCPriority%1").arg(j);
                params.putInt(remainingPriorityKeys.toStdString(), 0);
              }
              break;
            }

            updateToggles();
          } else {
            break;
          }
        }

        selectedPriorities.removeAll("None");
        slcPriorityButton->setValue(selectedPriorities.join(", "));
      });

      QStringList initialPriorities;
      for (int i = 1; i <= 3; ++i) {
        QString priorityKey = QString("SLCPriority%1").arg(i);
        std::string priorityValue = params.get(priorityKey.toStdString());
        QString priorityString = QString::fromStdString(priorityValue);
        if (!priorityString.isEmpty() && primaryPriorities.contains(priorityString) && priorityString != "None") {
          initialPriorities.append(priorityString);
        }
      }
      slcPriorityButton->setValue(initialPriorities.join(", "));
      addItem(slcPriorityButton);

    } else if (param == "VisionTurnControl") {
      FrogPilotParamManageControl *visionTurnControlToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(visionTurnControlToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(visionTurnControlKeys.find(key.c_str()) != visionTurnControlKeys.end());
        }
      });
      toggle = visionTurnControlToggle;
    } else if (param == "CurveSensitivity" || param == "TurnAggressiveness") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 1, 200, std::map<int, QString>(), this, false, "%");

    } else {
      toggle = new ParamControl(param, title, desc, icon, this);
    }

    addItem(toggle);
    toggles[param.toStdString()] = toggle;

    QObject::connect(toggle, &ToggleControl::toggleFlipped, [this]() {
      updateToggles();
    });

    QObject::connect(static_cast<FrogPilotButtonParamControl*>(toggle), &FrogPilotButtonParamControl::buttonClicked, [this]() {
      updateToggles();
    });

    QObject::connect(static_cast<FrogPilotParamValueControl*>(toggle), &FrogPilotParamValueControl::valueChanged, [this]() {
      updateToggles();
    });

    QObject::connect(toggle, &AbstractControl::showDescriptionEvent, [this]() {
      update();
    });

    QObject::connect(static_cast<FrogPilotParamManageControl*>(toggle), &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
      update();
    });
  }

  QObject::connect(toggles["AlwaysOnLateralMain"], &ToggleControl::toggleFlipped, [this]() {
    if (params.getBool("AlwaysOnLateralMain")) {
      FrogPilotConfirmationDialog::toggleAlert(
      "WARNING: This isn't guaranteed to work, so if you run into any issues, please report it in the FrogPilot Discord!",
      "I understand the risks.", this);
    }
  });

  QObject::connect(toggles["MuteOverheated"], &ToggleControl::toggleFlipped, [this]() {
    if (params.getBool("MuteOverheated")) {
      FrogPilotConfirmationDialog::toggleAlert(
      "WARNING: This MAY cause premature wear or damage by running the device over comma's recommended temperature limits!",
      "I understand the risks.", this);
    }
  });

  std::set<std::string> rebootKeys = {"AlwaysOnLateral", "HigherBitrate", "NNFF", "UseLateralJerk"};
  for (const std::string &key : rebootKeys) {
    QObject::connect(toggles[key], &ToggleControl::toggleFlipped, [this, key]() {
      if (started) {
        if (FrogPilotConfirmationDialog::toggle("Reboot required to take effect.", "Reboot Now", this)) {
          Hardware::soft_reboot();
        }
      }
    });
  }

  QObject::connect(device(), &Device::interactiveTimeout, this, &FrogPilotControlsPanel::hideSubToggles);
  QObject::connect(parent, &SettingsWindow::closeParentToggle, this, &FrogPilotControlsPanel::hideSubToggles);
  QObject::connect(parent, &SettingsWindow::closeSubParentToggle, this, &FrogPilotControlsPanel::hideSubSubToggles);
  QObject::connect(parent, &SettingsWindow::updateMetric, this, &FrogPilotControlsPanel::updateMetric);
  QObject::connect(uiState(), &UIState::offroadTransition, this, &FrogPilotControlsPanel::updateCarToggles);
  QObject::connect(uiState(), &UIState::uiUpdate, this, &FrogPilotControlsPanel::updateState);

  hideSubToggles();
  updateMetric();
}

void FrogPilotControlsPanel::updateState(const UIState &s) {
  started = s.scene.started;
}

void FrogPilotControlsPanel::updateToggles() {
  std::thread([this]() {
    paramsMemory.putBool("FrogPilotTogglesUpdated", true);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    paramsMemory.putBool("FrogPilotTogglesUpdated", false);
  }).detach();
}

void FrogPilotControlsPanel::updateCarToggles() {
  steerRatioStock = params.getFloat("SteerRatioStock");

  if (steerRatioStock == 0.0) {
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, [this, timer]() {
      steerRatioStock = params.getFloat("SteerRatioStock");
      if (steerRatioStock != 0.0) {
        timer->stop();
        timer->deleteLater();

        FrogPilotParamValueControl *steerRatioToggle = static_cast<FrogPilotParamValueControl*>(toggles["SteerRatio"]);
        steerRatioToggle->setTitle(QString("Steer Ratio (Default: %1)").arg(steerRatioStock, 0, 'f', 2));
        steerRatioToggle->updateControl(steerRatioStock * 0.75, steerRatioStock * 1.25, "", 0.01);
        steerRatioToggle->refresh();
      }
    });
    timer->start();
  } else {
    FrogPilotParamValueControl *steerRatioToggle = static_cast<FrogPilotParamValueControl*>(toggles["SteerRatio"]);
    steerRatioToggle->setTitle(QString("Steer Ratio (Default: %1)").arg(steerRatioStock, 0, 'f', 2));
    steerRatioToggle->updateControl(steerRatioStock * 0.75, steerRatioStock * 1.25, "", 0.01);
    steerRatioToggle->refresh();
  }
}

void FrogPilotControlsPanel::updateMetric() {
  bool previousIsMetric = isMetric;
  isMetric = params.getBool("IsMetric");

  if (isMetric != previousIsMetric) {
    double distanceConversion = isMetric ? FOOT_TO_METER : METER_TO_FOOT;
    double speedConversion = isMetric ? MILE_TO_KM : KM_TO_MILE;
    params.putIntNonBlocking("CESpeed", std::nearbyint(params.getInt("CESpeed") * speedConversion));
    params.putIntNonBlocking("CESpeedLead", std::nearbyint(params.getInt("CESpeedLead") * speedConversion));
    params.putIntNonBlocking("LaneDetectionWidth", std::nearbyint(params.getInt("LaneDetectionWidth") * distanceConversion));
    params.putIntNonBlocking("MTSCLimit", std::nearbyint(params.getInt("MTSCLimit") * speedConversion));
    params.putIntNonBlocking("Offset1", std::nearbyint(params.getInt("Offset1") * speedConversion));
    params.putIntNonBlocking("Offset2", std::nearbyint(params.getInt("Offset2") * speedConversion));
    params.putIntNonBlocking("Offset3", std::nearbyint(params.getInt("Offset3") * speedConversion));
    params.putIntNonBlocking("Offset4", std::nearbyint(params.getInt("Offset4") * speedConversion));
    params.putIntNonBlocking("PauseLateralOnSignal", std::nearbyint(params.getInt("PauseLateralOnSignal") * speedConversion));
    params.putIntNonBlocking("SetSpeedOffset", std::nearbyint(params.getInt("SetSpeedOffset") * speedConversion));
    params.putIntNonBlocking("StoppingDistance", std::nearbyint(params.getInt("StoppingDistance") * distanceConversion));
  }

  FrogPilotParamValueControl *laneWidthToggle = static_cast<FrogPilotParamValueControl*>(toggles["LaneDetectionWidth"]);
  FrogPilotParamValueControl *mtscLimitToggle = static_cast<FrogPilotParamValueControl*>(toggles["MTSCLimit"]);
  FrogPilotParamValueControl *offset1Toggle = static_cast<FrogPilotParamValueControl*>(toggles["Offset1"]);
  FrogPilotParamValueControl *offset2Toggle = static_cast<FrogPilotParamValueControl*>(toggles["Offset2"]);
  FrogPilotParamValueControl *offset3Toggle = static_cast<FrogPilotParamValueControl*>(toggles["Offset3"]);
  FrogPilotParamValueControl *offset4Toggle = static_cast<FrogPilotParamValueControl*>(toggles["Offset4"]);
  FrogPilotParamValueControl *pauseLateralToggle = static_cast<FrogPilotParamValueControl*>(toggles["PauseLateralOnSignal"]);
  FrogPilotParamValueControl *setSpeedOffsetToggle = static_cast<FrogPilotParamValueControl*>(toggles["SetSpeedOffset"]);
  FrogPilotParamValueControl *stoppingDistanceToggle = static_cast<FrogPilotParamValueControl*>(toggles["StoppingDistance"]);

  if (isMetric) {
    offset1Toggle->setTitle("Speed Limit Offset (0-34 kph)");
    offset2Toggle->setTitle("Speed Limit Offset (35-54 kph)");
    offset3Toggle->setTitle("Speed Limit Offset (55-64 kph)");
    offset4Toggle->setTitle("Speed Limit Offset (65-99 kph)");

    offset1Toggle->setDescription("Set speed limit offset for limits between 0-34 kph.");
    offset2Toggle->setDescription("Set speed limit offset for limits between 35-54 kph.");
    offset3Toggle->setDescription("Set speed limit offset for limits between 55-64 kph.");
    offset4Toggle->setDescription("Set speed limit offset for limits between 65-99 kph.");

    laneWidthToggle->updateControl(0, 30, " meters", 10);

    mtscLimitToggle->updateControl(0, 99, " kph");

    offset1Toggle->updateControl(-99, 99, " kph");
    offset2Toggle->updateControl(-99, 99, " kph");
    offset3Toggle->updateControl(-99, 99, " kph");
    offset4Toggle->updateControl(-99, 99, " kph");

    pauseLateralToggle->updateControl(0, 150, " kph");
    setSpeedOffsetToggle->updateControl(0, 150, " kph");

    stoppingDistanceToggle->updateControl(0, 5, " meters");
  } else {
    offset1Toggle->setTitle("Speed Limit Offset (0-34 mph)");
    offset2Toggle->setTitle("Speed Limit Offset (35-54 mph)");
    offset3Toggle->setTitle("Speed Limit Offset (55-64 mph)");
    offset4Toggle->setTitle("Speed Limit Offset (65-99 mph)");

    offset1Toggle->setDescription("Set speed limit offset for limits between 0-34 mph.");
    offset2Toggle->setDescription("Set speed limit offset for limits between 35-54 mph.");
    offset3Toggle->setDescription("Set speed limit offset for limits between 55-64 mph.");
    offset4Toggle->setDescription("Set speed limit offset for limits between 65-99 mph.");

    laneWidthToggle->updateControl(0, 100, " feet", 10);

    mtscLimitToggle->updateControl(0, 99, " mph");

    offset1Toggle->updateControl(-99, 99, " mph");
    offset2Toggle->updateControl(-99, 99, " mph");
    offset3Toggle->updateControl(-99, 99, " mph");
    offset4Toggle->updateControl(-99, 99, " mph");

    pauseLateralToggle->updateControl(0, 99, " mph");
    setSpeedOffsetToggle->updateControl(0, 99, " mph");

    stoppingDistanceToggle->updateControl(0, 10, " feet");
  }

  laneWidthToggle->refresh();
  mtscLimitToggle->refresh();
  offset1Toggle->refresh();
  offset2Toggle->refresh();
  offset3Toggle->refresh();
  offset4Toggle->refresh();
  pauseLateralToggle->refresh();
  setSpeedOffsetToggle->refresh();
  stoppingDistanceToggle->refresh();

  previousIsMetric = isMetric;
}

void FrogPilotControlsPanel::parentToggleClicked() {
  aggressiveProfile->setVisible(false);
  conditionalSpeedsImperial->setVisible(false);
  conditionalSpeedsMetric->setVisible(false);
  modelSelectorButton->setVisible(false);
  slcPriorityButton->setVisible(false);
  standardProfile->setVisible(false);
  relaxedProfile->setVisible(false);

  openParentToggle();
}

void FrogPilotControlsPanel::subParentToggleClicked() {
  openSubParentToggle();
}

void FrogPilotControlsPanel::hideSubToggles() {
  aggressiveProfile->setVisible(false);
  conditionalSpeedsImperial->setVisible(false);
  conditionalSpeedsMetric->setVisible(false);
  modelSelectorButton->setVisible(true);
  slcPriorityButton->setVisible(false);
  standardProfile->setVisible(false);
  relaxedProfile->setVisible(false);

  for (auto &[key, toggle] : toggles) {
    bool subToggles = aolKeys.find(key.c_str()) != aolKeys.end() ||
                      conditionalExperimentalKeys.find(key.c_str()) != conditionalExperimentalKeys.end() ||
                      experimentalModeActivationKeys.find(key.c_str()) != experimentalModeActivationKeys.end() ||
                      fireTheBabysitterKeys.find(key.c_str()) != fireTheBabysitterKeys.end() ||
                      laneChangeKeys.find(key.c_str()) != laneChangeKeys.end() ||
                      lateralTuneKeys.find(key.c_str()) != lateralTuneKeys.end() ||
                      longitudinalTuneKeys.find(key.c_str()) != longitudinalTuneKeys.end() ||
                      mtscKeys.find(key.c_str()) != mtscKeys.end() ||
                      qolKeys.find(key.c_str()) != qolKeys.end() ||
                      speedLimitControllerKeys.find(key.c_str()) != speedLimitControllerKeys.end() ||
                      speedLimitControllerControlsKeys.find(key.c_str()) != speedLimitControllerControlsKeys.end() ||
                      speedLimitControllerQOLKeys.find(key.c_str()) != speedLimitControllerQOLKeys.end() ||
                      speedLimitControllerVisualsKeys.find(key.c_str()) != speedLimitControllerVisualsKeys.end() ||
                      visionTurnControlKeys.find(key.c_str()) != visionTurnControlKeys.end();
    toggle->setVisible(!subToggles);
  }

  closeParentToggle();
}

void FrogPilotControlsPanel::hideSubSubToggles() {
  slcPriorityButton->setVisible(false);

  for (auto &[key, toggle] : toggles) {
    bool isVisible = speedLimitControllerKeys.find(key.c_str()) != speedLimitControllerKeys.end();
    toggle->setVisible(isVisible);
  }

  closeSubParentToggle();
  update();
}

void FrogPilotControlsPanel::hideEvent(QHideEvent *event) {
  hideSubToggles();
}
