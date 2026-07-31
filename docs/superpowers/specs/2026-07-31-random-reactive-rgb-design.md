# Keychron Q5 Max 무작위 컬러 반응형 RGB 이펙트 설계서

## 1. 개요
본 설계서는 Keychron Q5 Max (ANSI Encoder) 키보드에 키 입력 시 무작위(Random) 색상으로 켜지는 2가지 신규 RGB Matrix 이펙트(`SOLID_REACTIVE_SIMPLE_RANDOM`, `SOLID_REACTIVE_MULTIWIDE_RANDOM`)를 추가하고, `info.json` 설정을 통해 지속적으로 선택/사용 가능하도록 구현하는 방안을 다룹니다.

## 2. 신규 RGB Matrix 이펙트 명세

### 2.1 `SOLID_REACTIVE_SIMPLE_RANDOM` (무작위 단일 반응형)
- **동작**: 키보드의 특정 키를 타건했을 때, 해당 키 1개 위치에 **100% 무작위(Random) HUE** 색상의 빛이 켜진 후 지정된 시간에 따라 서서히 Fade-out되며 꺼집니다.
- **특징**: 기존 `SOLID_REACTIVE_SIMPLE`의 단색 한계를 극복하여 누를 때마다 각 키별로 알록달록한 랜덤 컬러가 연출됩니다.

### 2.2 `SOLID_REACTIVE_MULTIWIDE_RANDOM` (무작위 멀티 와이드 반응형)
- **동작**: 특정 키를 타건했을 때, 누른 지점을 중심으로 **무작위 컬러의 빛이 퍼져나가며 넓은 영역이 점등**되었다가 Fade-out됩니다.
- **특징**: 기존 `SOLID_REACTIVE_MULTIWIDE` 효과에 무작위 색상 오프셋을 조합하여 다채로운 타건 이펙트를 선사합니다.

## 3. 구현 아키텍처 및 파일 변경 계획

1. **`keyboards/keychron/q5_max/info.json`**:
   - `rgb_matrix.animations` 속성에 신규 이펙트 활성화 키 추가:
     ```json
     "solid_reactive_simple_random": true,
     "solid_reactive_multiwide_random": true
     ```

2. **QMK RGB Matrix 애니메이션 모듈 (`quantum/rgb_matrix/animations/`)**:
   - 신규 애니메이션 헤더 `solid_reactive_simple_random_anim.h` 및 `solid_reactive_multiwide_random_anim.h` 작성 또는 `rgb_matrix_user.inc` 연동.
   - `g_last_hit_tracker` 타임스탬프 또는 해시 함수 기반으로 누를 때마다 새로운 무작위 Hue 계산 로직 내장.

3. **EEPROM 저장 및 모드 선택**:
   - `RGB_MOD` 키 입력 및 VIA 모드 선택 시 이펙트 번호로 할당되어 키보드 EEPROM에 상태가 자동 저장됨.
