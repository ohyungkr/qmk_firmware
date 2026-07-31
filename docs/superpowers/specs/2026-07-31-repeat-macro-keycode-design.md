# QMK REPEAT(M0) 무한 반복 매크로 키코드 설계서

## 1. 개요
본 설계서는 Keychron Q5 Max 키보드의 키맵에서 `REPEAT(M0)`, `REPEAT(M1)` 형태로 사용하여, 한 번 클릭 시 해당 매크로를 무한 반복 실행하고 다시 클릭 시 중지/취소할 수 있는 파라미터형 커스텀 키코드(`REPEAT(n)`)의 구현 방안을 정의합니다.

## 2. 사용자 지정 키코드 명세

```c
#define M0  0
#define M1  1
#define M2  2
#define M3  3
#define M4  4
#define M5  5
#define M6  6
#define M7  7
#define M8  8
#define M9  9
#define M10 10
#define M11 11
#define M12 12
#define M13 13
#define M14 14
#define M15 15

enum user_custom_keycodes {
    RPT_M0 = QK_USER,
    RPT_M1,
    RPT_M2,
    RPT_M3,
    RPT_M4,
    RPT_M5,
    RPT_M6,
    RPT_M7,
    RPT_M8,
    RPT_M9,
    RPT_M10,
    RPT_M11,
    RPT_M12,
    RPT_M13,
    RPT_M14,
    RPT_M15,
};

#define REPEAT(n) (RPT_M0 + (n))
```

## 3. 동작 메커니즘 및 내부 로직

1. **`process_record_user` (이벤트 감지)**:
   - 입력된 `keycode`가 `RPT_M0` ~ `RPT_M15` 범위 내에 속하고 `record->event.pressed`인 경우:
     - 현재 진행 중인 매크로 ID가 눌린 매크로 ID와 동일하면 -> 반복 상태 해제 (`active_repeat_macro = -1`)
     - 다른 매크로이거나 비활성화 상태이면 -> 해당 매크로 ID로 활성화 (`active_repeat_macro = macro_id`) 및 타이머 초기화 (`repeat_timer = timer_read32()`).

2. **`matrix_scan_user` (무한 루프 송출)**:
   - `active_repeat_macro != -1` 상태이고 `timer_elapsed32(repeat_timer) >= REPEAT_INTERVAL_MS` 조건 만족 시:
     - `repeat_timer = timer_read32()`
     - `dynamic_keymap_macro_send(active_repeat_macro)`를 호출하여 VIA/QMK 매크로 자동 수행.
