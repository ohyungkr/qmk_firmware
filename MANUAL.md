# Keychron Q5 Max QMK VIA 펌웨어 사용 및 관리자 가이드

본 가이드는 Keychron Q5 Max (ANSI 배열) 키보드의 QMK 펌웨어를 빌드하고 커스텀 기능을 추가하는 상세 설명서입니다.

---

## 1. 빌드 환경 구성 (QMK MSYS)

### 1.1 QMK MSYS 설치 및 소스 디렉토리 이동
QMK MSYS 터미널을 실행한 뒤 작업 디렉토리로 이동합니다:
```bash
cd /f/Programing/Keyboard/Keychron_Q5_Max
```

### 1.2 GitHub Remote 구성
- **개인 포크 저장소 (`origin`)**: `https://github.com/ohyungkr/qmk_firmware.git`
- **공식 원본 저장소 (`upstream`)**: `https://github.com/Keychron/qmk_firmware.git`
- **현재 메인 브랜치**: `2025q3`

---

## 2. Q5 Max ANSI 펌웨어 컴파일

### 2.1 타겟 경로 확인
- **키보드 타겟**: `keychron/q5_max/ansi_encoder`
- **키맵 타겟**: `keychron` (또는 `via`)

### 2.2 빌드 명령어
QMK MSYS 터미널에서 아래 명령을 구동합니다:

```bash
# Keychron Q5 Max ANSI Encoder 타겟 펌웨어 컴파일
qmk compile -kb keychron/q5_max/ansi_encoder -km keychron
# 또는
make keychron/q5_max/ansi_encoder:keychron
```

### 2.3 빌드 결과물
- 컴파일 완료 후 생성 파일: `keychron_q5_max_ansi_encoder_keychron.bin`
- 산출물은 `.build/` 디렉토리에 저장됩니다.

---

## 3. 신규 커스텀 기능 및 이펙트 안내
- **무한 반복 매크로 키코드 (`REPEAT(M0)` ~ `REPEAT(M15)`)**:
  - `keymap.c` 레이아웃에서 `REPEAT(M0)`, `REPEAT(M1)` 형태로 지정.
  - 한 번 클릭 시 해당 VIA 매크로 무한 반복 시작, 다시 클릭 시 즉시 취소/중지.
  - **[무한 매크로 개발 기록 참조](./docs/dev/implement_20260731_204900.md)**
- **무작위 반응형 RGB 이펙트 2종 추가**:
  - `SOLID_REACTIVE_SIMPLE_RANDOM`: 단일 타건 키가 무작위(Random) 컬러로 점등 후 Fade-out.
  - `SOLID_REACTIVE_MULTIWIDE_RANDOM`: 타건 시 무작위 컬러 파동이 퍼진 후 Fade-out.
  - **[RGB 개발 구현 기록 참조](./docs/dev/implement_20260731_204100.md)**


---

## 4. 기존 커스텀 기능 가이드

상세한 소스코드 분석 및 알고리즘 설계는 **[개발 설계 문서 (implement_20260731_203400.md)](./docs/dev/implement_20260731_203400.md)**를 참조하시기 바랍니다.

1. **토글형 무한 반복 매크로 키**:
   - `keyboards/keychron/q5_max/ansi_encoder/keymaps/keychron/keymap.c`에 커스텀 키코드 및 `process_record_user`, `matrix_scan_user` 타이머 로직 구현.
2. **LED Typing Heatmap 이펙트**:
   - `info.json`에 `typing_heatmap: true` 활성화 확인. `config.h` 내 식는 속도/온도 범위 파라미터 매크로 커스텀 조정.
