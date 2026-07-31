# Keychron Q5 Max QMK VIA 펌웨어 저장소

본 저장소는 **Keychron Q5 Max (ANSI Encoder 배열)** 키보드의 QMK VIA 호환 커스텀 펌웨어 빌드 환경 및 소스코드를 관리하는 프로젝트입니다.  
Keychron 공식 무선 QMK 레포지토리(`wireless_playground` 브랜치)를 [ohyungkr/qmk_firmware](https://github.com/ohyungkr/qmk_firmware)로 포크(Fork)하여 개인 관리 중입니다.


---

## 📌 주요 특징
- **키보드 모델**: Keychron Q5 Max (ANSI Layout + Knob Encoder)
- **키보드 타겟**: `keychron/q5_max/ansi_encoder`
- **키맵 타겟**: `via`
- **컴파일 환경**: Windows 11 PowerShell + QMK MSYS

---

## 🛠️ 빠른 시작 (Quick Start)

### 1. 전제 조건 (Prerequisites)
- [QMK MSYS](https://msys.qmk.fm/) 설치 (Windows 11 환경)
- [VIA](https://usevia.app/) 또는 [Keychron Launcher](https://launcher.keychron.com/) (펌웨어 플래싱 및 키맵 변경용)

### 2. 펌웨어 컴파일 (Compile)
QMK MSYS 터미널을 실행 후 본 디렉토리로 이동하여 아래 명령어를 실행합니다:

```bash
# Keychron Q5 Max ANSI Encoder 타겟 VIA 펌웨어 빌드
qmk compile -kb keychron/q5_max/ansi_encoder -km via
```

빌드가 성공하면 최상위 디렉토리 또는 `.build/` 디렉토리에 `keychron_q5_max_ansi_encoder_via.bin` 산출물이 생성됩니다.

---

## 📖 문서 가이드 (Documentation)
- [사용 및 관리자 가이드](./docs/manual.md): QMK MSYS 설정, 키맵 수정 상세 방법 및 펌웨어 플래싱 절차
- [개발 구현 기록](./docs/dev/implement_20260731_194748.md): 환경 구성 이력 및 빌드 타겟 알고리즘 정리
