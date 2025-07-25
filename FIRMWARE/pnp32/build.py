#!/usr/bin/env python3
import re
import subprocess
import sys

def detect_env():
    try:
        with open("src/config.h", "r", encoding="utf-8") as f:
            content = f.read()
    except FileNotFoundError:
        print("❌ config.h not found!")
        sys.exit(1)

    match = re.search(r'^\s*#define\s+(PnP_Controller|pnp32_MC|pnp32_MCH|pnp32_MCM)\b', content, re.MULTILINE)
    if not match:
        print("❌ No valid #define found in config.h!")
        sys.exit(1)

    env = match.group(1)
    print(f"➡️  Detekovaný build environment: {env}")
    return env

env = detect_env()

# Spusti platformio s detekovaným env
subprocess.run(["platformio", "run", "-e", env], check=True)
