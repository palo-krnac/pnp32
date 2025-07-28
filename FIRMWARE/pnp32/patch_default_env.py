def build_command(env_name: str) -> list[str]:
    """Create a PlatformIO command for the detected environment.
    We forward only user-supplied flags (--target/-t and --upload-port/-p).
    """
    cmd = ["platformio", "run", "-e", env_name]

    args = sys.argv[1:]
    upload_port = None
    targets = []

    i = 0
    while i < len(args):
        arg = args[i]
        # Preskoč pôvodné -e/--environment a hodnotu
        if arg in ("-e", "--environment"):
            i += 2
            continue
        # --target <value>
        if arg == "--target" and i + 1 < len(args):
            targets.append(args[i + 1])
            i += 2
            continue
        # -t <value>
        if arg == "-t" and i + 1 < len(args):
            targets.append(args[i + 1])
            i += 2
            continue
        # --upload-port <value>
        if arg == "--upload-port" and i + 1 < len(args):
            upload_port = args[i + 1]
            i += 2
            continue
        # -p <value>
        if arg == "-p" and i + 1 < len(args):
            upload_port = args[i + 1]
            i += 2
            continue
        # ostatné parametre ignorujeme (sú to interné voľby PlatformIO)
        i += 1

    # pripoj nájdené ciele a upload port
    for t in targets:
        cmd.extend(["--target", t])
    if upload_port:
        cmd.extend(["--upload-port", upload_port])

    return cmd
