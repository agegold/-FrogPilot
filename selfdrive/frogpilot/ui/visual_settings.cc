#include "selfdrive/frogpilot/ui/visual_settings.h"

FrogPilotVisualsPanel::FrogPilotVisualsPanel(SettingsWindow *parent) : FrogPilotListWidget(parent) {
  const std::vector<std::tuple<QString, QString, QString, QString>> visualToggles {
    {"CustomTheme", "사용자 정의 테마", "사용자 정의 테마를 사용하는 기능을 활성화합니다.", "../frogpilot/assets/wheel_images/frog.png"},
    {"HolidayThemes", "휴일 테마", "현재/다가오는 공휴일에 따라 오픈파일럿 테마가 변경됩니다. 작은 공휴일은 하루 동안 지속되고, 주요 공휴일(부활절, 크리스마스, 할로윈 등)은 일주일 동안 지속됩니다.", ""},
    {"CustomColors", "색상 테마", "표준 Openpilot 색 구성표를 사용자 지정 색 구성표로 전환하세요.\n\n자신만의 색 구성표를 제출하고 싶으십니까? FrogPilot Discord의 '기능 요청' 채널에 게시하세요!", ""},
    {"CustomIcons", "아이콘 팩", "표준 Openpilot 아이콘을 사용자 정의 아이콘 세트로 전환하세요.\n\n자신만의 아이콘 팩을 제출하고 싶으십니까? FrogPilot Discord의 '기능 요청' 채널에 게시하세요!", ""},
    {"CustomSignals", "방향 지시등", "개인적인 터치를 위해 방향 지시등에 사용자 정의 애니메이션을 추가하세요!\n\n자신만의 방향 지시등 애니메이션을 제출하고 싶으십니까? FrogPilot Discord의 '기능 요청' 채널에 게시하세요!", ""},
    {"CustomSounds", "사운드 팩", "표준 오픈파일럿 사운드를 사용자 정의 사운드 세트로 전환하세요.\n\n자신만의 사운드 팩을 제출하고 싶으십니까? FrogPilot Discord의 '기능 요청' 채널에 게시하세요!", ""},

    {"AlertVolumeControl", "경고 볼륨 제어", "openpilot에서 각 개별 사운드의 볼륨 레벨을 제어합니다.", "../frogpilot/assets/toggle_icons/icon_mute.png"},
    {"DisengageVolume", "비작동 볼륨 ", "관련 경고:\n\n어댑티브 크루즈 비활성화\n주차 브레이크 작동\n페달 밟음\n속도가 너무 낮음", ""},
    {"EngageVolume", "작동 볼륨", "관련 경고:\n\nNNFF 토크 컨트롤러 로드됨", ""},
    {"PromptVolume", "프롬프트 볼륨", "관련 경고:\n\n사각지대에서 차량이 감지됨\n신호등이 녹색으로 바뀌었습니다\n속도가 너무 낮습니다\n'X' 이하에서는 조향을 사용할 수 없습니다\n조종권을 확보하고 조향 한계를 초과합니다.", ""},
    {"PromptDistractedVolume", "신속한 산만한 볼륨", "관련 경고:\n\n주의, 운전자 주의 분산\n핸들 터치, 운전자 무반응", ""},
    {"RefuseVolume", "거부 볼륨", "관련 경고:\n\nopenpilot 사용할 수 없음", ""},
    {"WarningSoftVolume", "경고 소프트 볼륨", "관련 경고:\n\n브레이크!, 충돌 위험\n즉시 제어하십시오", ""},
    {"WarningImmediateVolume", "즉시 볼륨 경고", "관련 경고:\n\n즉시 해제, 운전자 주의가 산만해짐\n즉시 해제, 운전자 응답 없음", ""},

    {"CameraView", "카메라 보기", "onroad UI에 대해 선호하는 카메라 보기를 선택하십시오. 이는 시각적인 변경일 뿐이며 openpilot에는 영향을 주지 않습니다.", "../frogpilot/assets/toggle_icons/icon_camera.png"},
    {"Compass", "나침반", "온로드 UI에 나침반을 추가하세요.", "../frogpilot/assets/toggle_icons/icon_compass.png"},

    {"CustomAlerts", "사용자 정의 경고", "다양한 논리 또는 상황 변화에 대한 사용자 정의 경고를 활성화합니다.", "../frogpilot/assets/toggle_icons/icon_green_light.png"},
    {"GreenLightAlert", "녹색 신호등 알림", "신호등이 빨간색에서 녹색으로 바뀔 때 알림을 받습니다..", ""},
    {"LeadDepartingAlert", "선두 출발 알림", "주차 차량이 정지 상태에서 출발하기 시작하면 알림을 받습니다.", ""},
    {"LoudBlindspotAlert", "시끄러운 사각지대 경고", "차선 변경을 시도할 때 사각지대에서 차량이 감지될 때 더 큰 소리로 경고를 활성화합니다.", ""},
    {"SpeedLimitChangedAlert", "속도 제한 변경 경고", "현재 속도 제한이 변경될 때마다 경고를 트리거합니다.", ""},

    {"CustomUI", "사용자 정의 Onroad UI", "일부 추가 시각적 기능으로 Onroad UI를 사용자 정의하세요.", "../assets/offroad/icon_road.png"},
    {"AccelerationPath", "가속 경로", "자동차의 의도된 가속 또는 감속을 색상으로 구분된 경로로 시각화합니다.", ""},
    {"AdjacentPath", "인접 경로", "자동차의 왼쪽과 오른쪽에 경로를 표시하여 모델이 차선을 감지하는 위치를 시각화합니다..", ""},
    {"BlindSpotPath", "사각지대 경로", "근처에 다른 차량이 감지되면 빨간색 경로로 사각지대를 시각화합니다.", ""},
    {"FPSCounter", "FPS 카운터", "시스템 성능 모니터링을 위해 온로드 UI의 초당 프레임 수(FPS)를 표시합니다..", ""},
    {"LeadInfo", "리드 정보 및 로직", "속도, 거리, 추종 거리 뒤에 숨어 있는 논리를 포함하여 전방 차량에 대한 자세한 정보를 얻으세요.", ""},
    {"PedalsOnUI", "누르고 있는 페달", "핸들 아이콘 아래 온로드 UI에 어떤 페달을 밟고 있는지 표시합니다.", ""},
    {"RoadNameUI", "도로 이름", "화면 하단에서 현재 도로 이름을 확인하세요. 출처는 OpenStreetMap입니다.", ""},

    {"DriverCamera", "후진 시 운전가 카메라", "후진 기어로 변속할 때 운전자 카메라를 보여줍니다.", "../assets/img_driver_face_static.png"},

    {"ModelUI", "모델 UI", "모델의 시각화가 화면에 표시되는 방식을 개인화하세요.", "../assets/offroad/icon_calibration.png"},
    {"DynamicPathWidth", "동적 경로 너비", "openpilot의 현재 참여 상태에 따라 경로 너비를 동적으로 조정합니다.", ""},
    {"HideLeadMarker", "선행차량 마커 숨기기", "온로드 UI에서 선행 차량 마커를 숨깁니다.", ""},
    {"LaneLinesWidth", "차선 선", "디스플레이에서 차선의 시각적 두께를 조정합니다.\n\n기본값은 MUTCD 평균 4인치와 일치합니다.", ""},
    {"PathEdgeWidth", "경로 가장자리", "UI에 표시되는 경로 가장자리의 너비를 조정하여 다양한 운전 모드와 상태를 나타냅니다.\n\n기본값은 전체 경로의 20%입니다.\n\n파란색 = 내비게이션\n밝은 파란색 = 항상 켜짐 측면\n녹색 = 기본값 'FrogPilot 색상'\n밝은 녹색 = 기본 색상의 기본값\n주황색 = 실험 모드 활성화\n노란색 = 조건부 재정의", ""},
    {"PathWidth", "경로 너비", "UI에 표시되는 주행 경로의 너비를 맞춤설정하세요.\n\n기본값은 2019 Lexus ES 350의 너비와 일치합니다.", ""},
    {"RoadEdgesWidth", "도로 가장자리", "디스플레이에서 도로 가장자리의 시각적 두께를 조정합니다.\n\n기본값은 MUTCD 평균 차선 폭 4인치의 1/2입니다.", ""},
    {"UnlimitedLength", "'무제한' 도로 UI 길이", "시스템이 감지할 수 있는 만큼 경로, 차선, 도로 가장자리 표시를 확장하여 전방 도로에 대한 더 넓은 시야를 제공합니다.", ""},

    {"NumericalTemp", "수치적 온도 게이지", "GOOD', 'OK', 'HIGH' 온도 상태를 메모리, CPU, GPU 간의 최고 온도를 기준으로 수치형 온도 게이지로 교체합니다.", "../frogpilot/assets/toggle_icons/icon_temperature.png"},

    {"QOLVisuals", "Quality of Life", "Miscellaneous quality of life changes to improve your overall openpilot experience.", "../frogpilot/assets/toggle_icons/quality_of_life.png"},
    {"DriveStats", "홈 화면의 드라이브 통계", "화면에 장치의 드라이브 통계를 표시합니다.", ""},
    {"FullMap", "전체 크기 지도", "로드 UI에서 지도 크기를 최대화합니다.", ""},
    {"HideSpeed", "속도 숨기기", "onroad UI에서 속도 표시를 숨깁니다. 추가 토글을 사용하면 속도 자체를 탭하여 숨기거나 표시할 수 있습니다.", ""},
    {"MapStyle", "지도 스타일", "openpilot에서 탐색'에 사용할 사용자 정의 지도 스타일을 사용하십시오.'.", ""},
    {"WheelSpeed", "휠 속도 사용", "위적인 속도가 아닌 휠 속도 측정법을 사용합니다.", ""},

    {"RandomEvents", "랜덤 이벤트", "특정 운전 조건에서 발생할 수 있는 무작위 이벤트로 약간의 예측 불가능성을 즐겨보세요.", "../frogpilot/assets/toggle_icons/icon_random.png"},

    {"ScreenManagement", "화면 관리", "화면 밝기, 시간 제한 설정을 관리하고 특정 온로드 UI 요소를 숨깁니다.", "../frogpilot/assets/toggle_icons/icon_light.png"},
    {"HideUIElements", "UI 요소 숨기기", "온로드 화면에서 선택한 UI 요소를 숨깁니다..", ""},
    {"ScreenBrightness", "화면 밝기", "오프로드 시 화면 밝기를 사용자 정의하세요.", ""},
    {"ScreenBrightnessOnroad", "화면 밝기(온로드)", "온로드 시 화면 밝기를 사용자 정의하세요.", ""},
    {"ScreenRecorder", "화면 녹화", "화면을 녹화하려면 화면 녹화 버튼을 활성화하세요.", ""},
    {"ScreenTimeout", "화면 꺼짐", "화면이 꺼지는 데 걸리는 시간을 사용자 정의하세요.", ""},
    {"ScreenTimeoutOnroad", "온로드시 화면 꺼짐", "도로 주행 후 화면이 꺼지는 데 걸리는 시간을 맞춤설정하세요.", ""},
    {"StandbyMode", "대기 모드", "도로에서 화면 시간이 초과되면 화면을 끄고 참여 상태가 변경되거나 중요한 알림이 실행되면 다시 깨우세요.", ""},

    {"WheelIcon", "운전대 아이콘", "기본 운전대 아이콘을 사용자 정의 디자인으로 교체하여 인터페이스에 독특한 터치를 추가하세요.", "../assets/offroad/icon_openpilot.png"},
  };

  for (const auto &[param, title, desc, icon] : visualToggles) {
    ParamControl *toggle;

    if (param == "AlertVolumeControl") {
      FrogPilotParamManageControl *alertVolumeControlToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(alertVolumeControlToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(alertVolumeControlKeys.find(key.c_str()) != alertVolumeControlKeys.end());
        }
      });
      toggle = alertVolumeControlToggle;
    } else if (alertVolumeControlKeys.find(param) != alertVolumeControlKeys.end()) {
      if (param == "WarningImmediateVolume") {
        toggle = new FrogPilotParamValueControl(param, title, desc, icon, 25, 100, std::map<int, QString>(), this, false, "%");
      } else {
        toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 100, std::map<int, QString>(), this, false, "%");
      }

    } else if (param == "CameraView") {
      std::vector<QString> cameraOptions{tr("Auto"), tr("Standard"), tr("Wide"), tr("Driver")};
      FrogPilotButtonParamControl *preferredCamera = new FrogPilotButtonParamControl(param, title, desc, icon, cameraOptions);
      toggle = preferredCamera;

    } else if (param == "CustomAlerts") {
      FrogPilotParamManageControl *customAlertsToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(customAlertsToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(customAlertsKeys .find(key.c_str()) != customAlertsKeys .end());
        }
      });
      toggle = customAlertsToggle;

    } else if (param == "CustomTheme") {
      FrogPilotParamManageControl *customThemeToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(customThemeToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(customThemeKeys.find(key.c_str()) != customThemeKeys.end());
        }
      });
      toggle = customThemeToggle;
    } else if (customThemeKeys.find(param) != customThemeKeys.end() && param != "HolidayThemes") {
      std::vector<QString> themeOptions{tr("Stock"), tr("Frog"), tr("Tesla"), tr("Stalin")};
      FrogPilotButtonParamControl *themeSelection = new FrogPilotButtonParamControl(param, title, desc, icon, themeOptions);
      toggle = themeSelection;

      if (param == "CustomSounds") {
        QObject::connect(static_cast<FrogPilotButtonParamControl*>(toggle), &FrogPilotButtonParamControl::buttonClicked, [this](int id) {
          if (id == 1) {
            if (FrogPilotConfirmationDialog::yesorno("Do you want to enable the bonus 'Goat' sound effect?", this)) {
              params.putBoolNonBlocking("GoatScream", true);
            } else {
              params.putBoolNonBlocking("GoatScream", false);
            }
          }
        });
      }

    } else if (param == "CustomUI") {
      FrogPilotParamManageControl *customUIToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(customUIToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(customOnroadUIKeys.find(key.c_str()) != customOnroadUIKeys.end());
        }
      });
      toggle = customUIToggle;
    } else if (param == "LeadInfo") {
      std::vector<QString> leadInfoToggles{"UseSI"};
      std::vector<QString> leadInfoToggleNames{tr("Use SI Values")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, leadInfoToggles, leadInfoToggleNames);
    } else if (param == "AdjacentPath") {
      std::vector<QString> adjacentPathToggles{"AdjacentPathMetrics"};
      std::vector<QString> adjacentPathToggleNames{tr("Display Metrics")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, adjacentPathToggles, adjacentPathToggleNames);

    } else if (param == "ModelUI") {
      FrogPilotParamManageControl *modelUIToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(modelUIToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(modelUIKeys.find(key.c_str()) != modelUIKeys.end());
        }
      });
      toggle = modelUIToggle;
    } else if (param == "LaneLinesWidth" || param == "RoadEdgesWidth") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 24, std::map<int, QString>(), this, false, " inches");
    } else if (param == "PathEdgeWidth") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 100, std::map<int, QString>(), this, false, "%");
    } else if (param == "PathWidth") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 100, std::map<int, QString>(), this, false, " feet", 10);

    } else if (param == "NumericalTemp") {
      std::vector<QString> temperatureToggles{"Fahrenheit"};
      std::vector<QString> temperatureToggleNames{tr("Fahrenheit")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, temperatureToggles, temperatureToggleNames);

    } else if (param == "QOLVisuals") {
      FrogPilotParamManageControl *qolToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(qolToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(qolKeys.find(key.c_str()) != qolKeys.end());
        }
        mapStyleButton->setVisible(true);
      });
      toggle = qolToggle;
    } else if (param == "HideSpeed") {
      std::vector<QString> hideSpeedToggles{"HideSpeedUI"};
      std::vector<QString> hideSpeedToggleNames{tr("Control Via UI")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, hideSpeedToggles, hideSpeedToggleNames);
    } else if (param == "MapStyle") {
      QMap<int, QString> styleMap = {
        {0, tr("Stock openpilot")},
        {1, tr("Mapbox Streets")},
        {2, tr("Mapbox Outdoors")},
        {3, tr("Mapbox Light")},
        {4, tr("Mapbox Dark")},
        {5, tr("Mapbox Satellite")},
        {6, tr("Mapbox Satellite Streets")},
        {7, tr("Mapbox Navigation Day")},
        {8, tr("Mapbox Navigation Night")},
        {9, tr("Mapbox Traffic Night")},
        {10, tr("mike854's (Satellite hybrid)")},
      };

      QStringList styles = styleMap.values();

      mapStyleButton = new ButtonControl(title, tr("SELECT"), desc);
      QObject::connect(mapStyleButton, &ButtonControl::clicked, this, [this, styleMap]() {
        QStringList styles = styleMap.values();
        QString selection = MultiOptionDialog::getSelection(tr("Select a map style"), styles, "", this);
        if (!selection.isEmpty()) {
          int selectedStyle = styleMap.key(selection);
          params.putInt("MapStyle", selectedStyle);
          mapStyleButton->setValue(selection);
          updateToggles();
        }
      });

      int currentStyle = params.getInt("MapStyle");
      mapStyleButton->setValue(styleMap[currentStyle]);

      addItem(mapStyleButton);

    } else if (param == "ScreenManagement") {
      FrogPilotParamManageControl *screenToggle = new FrogPilotParamManageControl(param, title, desc, icon, this);
      QObject::connect(screenToggle, &FrogPilotParamManageControl::manageButtonClicked, this, [this]() {
        parentToggleClicked();
        for (auto &[key, toggle] : toggles) {
          toggle->setVisible(screenKeys.find(key.c_str()) != screenKeys.end());
        }
      });
      toggle = screenToggle;
    } else if (param == "HideUIElements") {
      std::vector<QString> uiElementsToggles{"HideAlerts", "HideMapIcon", "HideMaxSpeed"};
      std::vector<QString> uiElementsToggleNames{tr("Alerts"), tr("Map Icon"), tr("Max Speed")};
      toggle = new FrogPilotParamToggleControl(param, title, desc, icon, uiElementsToggles, uiElementsToggleNames);
    } else if (param == "ScreenBrightness" || param == "ScreenBrightnessOnroad") {
      std::map<int, QString> brightnessLabels;
      for (int i = 0; i <= 101; ++i) {
        brightnessLabels[i] = i == 0 ? "Screen Off" : i == 101 ? "Auto" : QString::number(i) + "%";
      }
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 0, 101, brightnessLabels, this, false);
    } else if (param == "ScreenTimeout" || param == "ScreenTimeoutOnroad") {
      toggle = new FrogPilotParamValueControl(param, title, desc, icon, 5, 60, std::map<int, QString>(), this, false, " seconds");

    } else if (param == "WheelIcon") {
      std::vector<QString> wheelToggles{"RotatingWheel"};
      std::vector<QString> wheelToggleNames{tr("Rotating")};
      std::map<int, QString> steeringWheelLabels = {{-1, "None"}, {0, "Stock"}, {1, "Lexus"}, {2, "Toyota"}, {3, "Frog"}, {4, "Rocket"}, {5, "Hyundai"}, {6, "Stalin"}};
      toggle = new FrogPilotParamValueToggleControl(param, title, desc, icon, -1, 6, steeringWheelLabels, this, true, "", 1, wheelToggles, wheelToggleNames);

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

    QObject::connect(static_cast<FrogPilotParamManageControl*>(toggle), &FrogPilotParamManageControl::manageButtonClicked, [this]() {
      update();
    });
  }

  std::set<std::string> rebootKeys = {"DriveStats"};
  for (const std::string &key : rebootKeys) {
    QObject::connect(toggles[key], &ToggleControl::toggleFlipped, [this, key]() {
      if (started || key == "DriveStats") {
        if (FrogPilotConfirmationDialog::toggle("Reboot required to take effect.", "Reboot Now", this)) {
          Hardware::soft_reboot();
        }
      }
    });
  }

  QObject::connect(device(), &Device::interactiveTimeout, this, &FrogPilotVisualsPanel::hideSubToggles);
  QObject::connect(parent, &SettingsWindow::closeParentToggle, this, &FrogPilotVisualsPanel::hideSubToggles);
  QObject::connect(parent, &SettingsWindow::closeSubParentToggle, this, &FrogPilotVisualsPanel::hideSubSubToggles);
  QObject::connect(parent, &SettingsWindow::updateMetric, this, &FrogPilotVisualsPanel::updateMetric);
  QObject::connect(uiState(), &UIState::uiUpdate, this, &FrogPilotVisualsPanel::updateState);

  hideSubToggles();
  updateMetric();
}

void FrogPilotVisualsPanel::updateState(const UIState &s) {
  started = s.scene.started;
}

void FrogPilotVisualsPanel::updateToggles() {
  std::thread([this]() {
    paramsMemory.putBool("FrogPilotTogglesUpdated", true);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    paramsMemory.putBool("FrogPilotTogglesUpdated", false);
  }).detach();
}

void FrogPilotVisualsPanel::updateMetric() {
  bool previousIsMetric = isMetric;
  isMetric = params.getBool("IsMetric");

  if (isMetric != previousIsMetric) {
    double distanceConversion = isMetric ? INCH_TO_CM : CM_TO_INCH;
    double speedConversion = isMetric ? FOOT_TO_METER : METER_TO_FOOT;
    params.putIntNonBlocking("LaneLinesWidth", std::nearbyint(params.getInt("LaneLinesWidth") * distanceConversion));
    params.putIntNonBlocking("RoadEdgesWidth", std::nearbyint(params.getInt("RoadEdgesWidth") * distanceConversion));
    params.putIntNonBlocking("PathWidth", std::nearbyint(params.getInt("PathWidth") * speedConversion));
  }

  FrogPilotParamValueControl *laneLinesWidthToggle = static_cast<FrogPilotParamValueControl*>(toggles["LaneLinesWidth"]);
  FrogPilotParamValueControl *roadEdgesWidthToggle = static_cast<FrogPilotParamValueControl*>(toggles["RoadEdgesWidth"]);
  FrogPilotParamValueControl *pathWidthToggle = static_cast<FrogPilotParamValueControl*>(toggles["PathWidth"]);

  if (isMetric) {
    laneLinesWidthToggle->setDescription("Customize the lane line width.\n\nDefault matches the Vienna average of 10 centimeters.");
    roadEdgesWidthToggle->setDescription("Customize the road edges width.\n\nDefault is 1/2 of the Vienna average lane line width of 10 centimeters.");

    laneLinesWidthToggle->updateControl(0, 60, " centimeters");
    roadEdgesWidthToggle->updateControl(0, 60, " centimeters");
    pathWidthToggle->updateControl(0, 30, " meters", 10);
  } else {
    laneLinesWidthToggle->setDescription("Customize the lane line width.\n\nDefault matches the MUTCD average of 4 inches.");
    roadEdgesWidthToggle->setDescription("Customize the road edges width.\n\nDefault is 1/2 of the MUTCD average lane line width of 4 inches.");

    laneLinesWidthToggle->updateControl(0, 24, " inches");
    roadEdgesWidthToggle->updateControl(0, 24, " inches");
    pathWidthToggle->updateControl(0, 100, " feet", 10);
  }

  laneLinesWidthToggle->refresh();
  roadEdgesWidthToggle->refresh();

  previousIsMetric = isMetric;
}

void FrogPilotVisualsPanel::parentToggleClicked() {
  mapStyleButton->setVisible(false);

  openParentToggle();
}

void FrogPilotVisualsPanel::subParentToggleClicked() {
  mapStyleButton->setVisible(false);

  openSubParentToggle();
}

void FrogPilotVisualsPanel::hideSubToggles() {
  mapStyleButton->setVisible(false);

  for (auto &[key, toggle] : toggles) {
    bool subToggles = alertVolumeControlKeys.find(key.c_str()) != alertVolumeControlKeys.end() ||
                      customAlertsKeys.find(key.c_str()) != customAlertsKeys.end() ||
                      customOnroadUIKeys.find(key.c_str()) != customOnroadUIKeys.end() ||
                      customThemeKeys.find(key.c_str()) != customThemeKeys.end() ||
                      modelUIKeys.find(key.c_str()) != modelUIKeys.end() ||
                      qolKeys.find(key.c_str()) != qolKeys.end() ||
                      screenKeys.find(key.c_str()) != screenKeys.end();
    toggle->setVisible(!subToggles);
  }

  closeParentToggle();
}

void FrogPilotVisualsPanel::hideSubSubToggles() {
  for (auto &[key, toggle] : toggles) {
    bool isVisible = false;
    toggle->setVisible(isVisible);
  }

  closeSubParentToggle();
  update();
}

void FrogPilotVisualsPanel::hideEvent(QHideEvent *event) {
  hideSubToggles();
}
