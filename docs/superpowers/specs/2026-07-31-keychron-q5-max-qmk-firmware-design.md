# Keychron Q5 Max QMK VIA 펌웨어 빌드 및 Git 관리 환경 설계서

## 1. 개요
본 설계서는 Keychron Q5 Max 키보드의 QMK VIA 펌웨어 빌드 환경을 구축하고, Windows 11(PowerShell & QMK MSYS) 환경에서 소스 코드 및 관련 문서를 Git으로 체계적으로 관리하기 위한 설계 문서입니다.

## 2. 저장소 및 프로젝트 구조
Keychron의 무선 QMK 공식 브랜치(`wireless_playground`)를 기반으로 현재 디렉토리(`f:\Programing\Keyboard\Keychron_Q5_Max`)에 QMK 펌웨어 소스를 구성합니다.

```text
Keychron_Q5_Max/
├── .gitignore                      # Git 추적 제외 설정
├── README.md                       # 프로젝트 메인 설명서
├── docs/
│   ├── manual.md                   # 사용 및 관리자 가이드 (빌드 및 플래싱)
│   └── dev/
│       └── implement_20260731_194700.md  # 최초 구현 기록
├── keyboards/
│   └── keychron/
│       └── q5_max/                 # Keychron Q5 Max 키보드 매핑 및 설정
└── ...                             # Keychron QMK Firmware 소스 코드
```

## 3. 사용자 규칙 및 Git 관리 기준
- **언어 및 인코딩**: 모든 문서, 주석, 가이드는 한국어(UTF-8)로 작성.
- **Git 제외 (.gitignore)**:
  - `./docs ./.agent` 및 하위 디렉토리 기본 제외 설정
  - QMK 빌드 생성물 (`.build/`, `*.bin`, `*.hex`, `*.uf2`) 제외
- **필수 문서 구성**:
  - `README.md`: 메인 프로젝트 안내 및 설치/빌드 요약
  - `docs/manual.md`: QMK MSYS 사용법, VIA 펌웨어 빌드 및 플래싱 가이드
  - `docs/dev/implement_{timestamp}.md`: 구현 작업 이력 및 환경 설정 기록

## 4. 빌드 파이프라인 (QMK MSYS)
1. Keychron 공식 QMK 레포지토리 `https://github.com/Keychron/qmk_firmware.git` (`wireless_playground` 브랜치) 수용.
2. QMK MSYS 터미널을 통한 펌웨어 컴파일:
   ```bash
   qmk compile -kb keychron/q5_max/ansi_encoder -km via
   ```
3. 산출물(`.bin` 등) 확인 및 키보드 QMK Toolbox / Web VIA / Web Flasher를 통한 펌웨어 업데이트.
