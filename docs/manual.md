# Keychron Q5 Max QMK VIA 펌웨어 사용 및 관리자 가이드

 본 가이드는 Keychron Q5 Max (ANSI 배열) 키보드의 QMK VIA 펌웨어를 빌드하고 수정하는 상세 설명서입니다.

---

## 1. 빌드 환경 구성 (QMK MSYS)

### 1.1 QMK MSYS 설치
1. [QMK MSYS 공식 웹사이트](https://msys.qmk.fm/)에서 Windows용 설치 프로그램을 다운로드하여 설치합니다.
2. QMK MSYS 터미널을 실행한 뒤, 초기 설정을 수행합니다:
   ```bash
   qmk setup
   ```

### 1.2 소스코드 디렉토리 연결 및 Git Remote
QMK MSYS 터미널에서 작업 디렉토리로 이동합니다:
```bash
cd /f/Programing/Keyboard/Keychron_Q5_Max
```

- **개인 포크 저장소 (`origin`)**: `https://github.com/ohyungkr/qmk_firmware.git`
- **공식 원본 저장소 (`upstream`)**: `https://github.com/Keychron/qmk_firmware.git`

#### Keychron 공식 최신 코드 동기화 방법:
```bash
git fetch upstream wireless_playground
git merge upstream/wireless_playground
git push origin wireless_playground
```


---

## 2. Q5 Max ANSI VIA 펌웨어 컴파일

### 2.1 타겟 경로 확인
- **키보드 타겟**: `keychron/q5_max/ansi_encoder`
- **키맵 디렉토리**: `keyboards/keychron/q5_max/ansi_encoder/keymaps/via`

### 2.2 빌드 명령어
QMK MSYS 터미널에서 아래 명령을 구동합니다:

```bash
qmk compile -kb keychron/q5_max/ansi_encoder -km via
```

### 2.3 빌드 결과물
- 컴파일 완료 후 생성 파일: `keychron_q5_max_ansi_encoder_via.bin`
- 산출물은 QMK root 또는 `.build/` 디렉토리에 저장됩니다.

---

## 3. 커스텀 키맵 수정 가이드

키맵 레이아웃이나 단축키 매핑을 코드 수준에서 변경하려는 경우 아래 소스파일을 편집합니다:

- **키맵 파일**: `keyboards/keychron/q5_max/ansi_encoder/keymaps/via/keymap.c`
- **설정 파일**: `keyboards/keychron/q5_max/ansi_encoder/keymaps/via/config.h`
- **빌드 옵션**: `keyboards/keychron/q5_max/ansi_encoder/keymaps/via/rules.mk`

---

## 4. 펌웨어 플래싱 (Flashing)

1. Keychron Q5 Max의 토글 스위치를 **OFF** (또는 Cable 모드)로 변경하고 USB 케이블을 연결합니다.
2. 키보드를 **Bootloader(DFU) 모드**로 진입시킵니다:
   - 방법 1: `Fn + B` 키 조합 입력
   - 방법 2: Spacebar 아래 또는 PCB 뒷면의 `RESET` 버튼 누름
3. **QMK Toolbox** 또는 **[Keychron Launcher Web Flasher](https://launcher.keychron.com/)**를 열고 빌드된 `keychron_q5_max_ansi_encoder_via.bin` 파일을 선택한 후 **Flash** 버튼을 클릭합니다.
4. 플래싱 완료 후 웹 기반 [usevia.app](https://usevia.app/)에 접속하여 키 매핑을 실시간으로 확인 및 조정합니다.
