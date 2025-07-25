Import("env")
import re
import os
import sys
import subprocess

def detect_board_define():
    try:
        with open("src/config.h", "r", encoding="utf-8") as f:
            content = f.read()
    except FileNotFoundError:
        print("❌ Súbor config.h neexistuje!")
        return "auto"

    match = re.search(r'^\s*#define\s+(PnP_Controller|pnp32_MC|pnp32_MCH|pnp32_MCM)\b', content, re.MULTILINE)
    if match:
        board_define = match.group(1)
        print(f"➡️  Detekovaný typ dosky z config.h: {board_define}")
        return board_define
    else:
        print("⚠️  Nenašiel sa žiadny typ dosky, používam 'auto'")
        return "auto"

env_name = detect_board_define()

# Ak sme v "auto", spustíme znova build ale v správnom env
if env_name != "auto":
    print(f"🔁 Prepnúť build na prostredie '{env_name}'")
    result = subprocess.run(["platformio", "run", "-e", env_name])
    # Ukonči tento build, aby sa nespustil duplicitne
    env.Exit(result.returncode)
