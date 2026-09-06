# Changelog

All notable changes to ProjetGit are documented here.

Format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).
Versioning follows [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

> ProjetGit is an archive of L2 coursework — three unrelated projects (C, SDL2,
> PHP) plus loose files. Entries below that predate this changelog were not
> versioned; they are reconstructed from the git history and the files
> themselves.

---

## [Unreleased]

### Security

- **Removed real personal data from `Students.csv`** and replaced it with an
  anonymised fixture of identical shape (same header, 41 records). The original
  file exposed names, birth dates, home addresses and phone numbers of 41 real
  students from 2024 to 2026. History purge still pending — see
  [SECURITY.md](SECURITY.md).
- **Removed inline MySQL credentials** (`root`/`h`) from the four PHP files;
  they now `require db.php` (gitignored). Template: `db.example.php`.
- **Untracked the compiled game binary** `prog` (now in `.gitignore`).

### Added

- Documentation set: this changelog, `README.md`, `CONTRIBUTING.md`,
  `SECURITY.md`, `CODE_OF_CONDUCT.md`, `LICENSE`, `.editorconfig`,
  `docs/BUILD.md`, and a `Makefile` with `records`, `game` and `clean` targets.
- CI (`.github/workflows/ci.yml`) building the C records program and linting the
  PHP sources.

---

## Before — reconstructed

### 2024 — initial import

- **C / Tri d'étudiants.** `main.c`, `eleve.c`, `eleve.h` — CSV sort over
  `Students.csv`.
- **SDL2 game.** `icone.c` plus the bitmap assets now flat at the root
  (`quiz/`, `snack/` subfolders never uploaded).
- **PHP / Chat One.** `index.php`, `cCompte.php`, `sCompte.php`, `chat.php`,
  `tchat.php`, `traiterCompte.php`, `test.php`, `security.php`,
  `verification_nom.php`, `retest.php`, stylesheets, `aide.txt`.
- `Students.csv` **containing real personal data of 41 students** was committed
  with this import and stayed public until September 2026.

### Unknown dates (later uploads)

- `snack.py` (py5 bouncing-ball sketch), `cv.html`, `snack_C.txt`, font and
  image assets added via the GitHub web interface.
- Passwords in Chat One were stored and compared in clear text throughout.

### 2026-09 — cleanup pass

- Repository documented; `.gitignore` created; PII fixture and credential
  removal (above); `Snack_C` branch (deleted-only, subset of `main`) left for
  the owner to delete.

[Unreleased]: https://github.com/Heritina-sys/ProjetGit/compare/main...HEAD
