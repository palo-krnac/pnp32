Import("env")
import re
import os

def detect_board_define():
    try:
        with open("src/config.h", "r", encoding="utf-8") as f:
            content = f.read()
    except FileNotFoundError:
        print("❌ Súbor config.h neexistuje!")
        env.Exit(1)

    match = re.search(r'^\s*#define\s+(PnP_Controller|pnp32_MC|pnp32_MCH|pnp32_MCM)\b', content, re.MULTILINE)
    if not match:
        print("❌ Nenašiel sa žiadny aktívny #define pre typ dosky v config.h!")
        env.Exit(1)

    board_define = match.group(1)
    print(f"➡️  Detekovaný typ dosky z config.h: {board_define}")

    # Prepneme na zodpovedajúce prostredie
    env_name = board_define
    os.environ["PLATFORMIO_BUILD_ENVIRONMENT"] = env_name

detect_board_define()

