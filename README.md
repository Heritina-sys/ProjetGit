# ProjetGit

Archive of second-year (L2) university coursework. Not a single application:
this repository stores **three unrelated student projects** and the loose files
around them, all uploaded through the GitHub web interface.

| Component | Language | What it is |
|---|---|---|
| [`tri_eleves`](#1-c--tri-détudiants) | C | Console app: parses `Students.csv`, sorts the students by surname |
| [`Snack Game`](#2-sdl2--snack-game) | C + SDL2 | Interactive bitmap game prototype (window *"Snack Game"*) |
| [`Chat One`](#3-php--chat-one) | PHP + MySQL | Minimal web chat with account creation and login |
| [`snack.py`](#4-python--snackpy) | Python (py5) | Small bouncing-ball sketch — unrelated to the SDL2 game |

Each component was a standalone assignment with its own requirements. They share
nothing but this repository. Read the section for the one you care about; the
rest is context.

> **Real personal data was removed from this repository.** `Students.csv` was
> originally a list of 41 real students with home addresses and phone numbers,
> public from 2024 to 2026. It is now an anonymised fixture — see
> [SECURITY.md](SECURITY.md) before touching it.

---

## 1. C — Tri d'étudiants

Reads the CSV file `Students.csv`, sorts the students by `Nom` (surname) and
prints the result.

```
Nom,Prénom,Date de naissance,Adresse,Tel,Genre,Parcours
ANDRIA,Hery,09/09/2005,…,0310000008,Homme,MIT
```

**Files.** `main.c` (driver), `eleve.h` (structure + declarations),
`eleve.c` (`fopen`/`getline`/`strtok` CSV parsing, `qsort` comparator),
`Students.csv` (fixture, **anonymised**).

```bash
make records          # or: gcc -std=c11 -D_GNU_SOURCE main.c eleve.c -o tri_eleves
./tri_eleves          # reads Students.csv from the current directory
```

See [docs/BUILD.md](docs/BUILD.md) for details, requirements and the caveats.

## 2. SDL2 — Snack Game

An interactive game written in C with the SDL2 library. `icone.c` opens an
800×600 window titled *"Snack Game"*, loads bitmap assets and renders the game
loop. The window title is the English word *Snack*; despite the name it is not
the same project as `snack.py`.

The assignment expected this layout (see `snack_C.txt`):

```
icone.c
quiz/   a.bmp c.bmp cible.bmp image.bmp k.bmp n.bmp s.bmp …
snack/  game_over.bmp pause.bmp play.bmp quitter.bmp Black\ Mortal\ TTF\ Personal.ttf
```

`icone.c` loads its assets from `quiz/` and `snack/`, so the bitmaps (currently
flat at the repository root) must be moved back into those two folders before it
will run. The font is loaded but the SDL_ttf code is commented out.

```bash
make game             # requires SDL2 development headers
./prog
```

## 3. PHP — Chat One

A minimal PHP chat:

| File | Role |
|---|---|
| `index.php` | Landing page with links to create an account or log in |
| `cCompte.php` / `traiterCompte.php` | Account creation (rejects a name that already exists) |
| `sCompte.php` / `test.php` | Login (name + password) |
| `chat.php` / `tchat.php` | Display the 10 latest messages and post one |
| `db.example.php` | **Template** for the DB connection — copy to `db.php` |
| `aide.txt` | The original assignment instructions |

Uses a MySQL database named `Message` with two tables, `Compte`
(`Nom`, `Password`, `date_creation`) and `Chat` (`Nom`, `message`,
`date_creation`) — schema in `aide.txt`.

**Layout.** The pages link their stylesheets as `../StpM/…`, so the original
assignment runs the PHP files from a `tpM/` folder with the CSS and images in a
sibling `StpM/` folder. The stylesheets and `utilisateur.png` live at the
repository root; recreate that layout (or fix the links) to run it:

```bash
mkdir -p tpM StpM
mv *.php db.example.php tpM/        # php sources (not this README!)
mv *.css utilisateur.png StpM/
cd tpM && cp db.example.php db.php  # then edit db.php with your credentials
```

**Database credentials are never committed.** The original code had a PDO
connection string — `new PDO(…, 'root', 'h')` — written directly into four PHP
files (see [SECURITY.md](SECURITY.md) for the incident). Each now requires
`db.php`, which is gitignored. Create it from `db.example.php`.

## 4. Python — `snack.py`

A tiny [py5](https://py5.xty.app/) sketch: a ball bouncing across a 400×400
canvas. Not the SDL2 game.

```bash
pip install py5
python snack.py
```

---

## Also here

- `icone.c` (see §2), `snack_C.txt` — the SDL2 assignment notes.
- `aide.txt` — the PHP assignment notes (layout, DB schema, the old inline
  credentials).
- `cv.html` — a static CV page (personal document; own work).
- `.bmp` files, `Black Mortal TTF Personal.ttf`, `utilisateur.png` — assets.

## Known limitations

### C / records (real defects, not style)

1. **Off-by-one / out-of-bounds in `main.c` + `eleve.c`.** `nombreEleve()`
   counts **newline characters**, so for a file of *N* records plus a header it
   returns *N+1*. `main.c` then allocates `N` records but `recupInfosEleve()`
   reads and `afficheEleve()` prints `N+1` of them — one write and one read past
   the allocation.
2. `main.c:9` — `sizeof(lUne)/sizeof(lUne[0])` on a pointer does **not** compute
   an array length (the compiler warns). The result is unused, but the line is
   misleading and should go.
3. No `_GNU_SOURCE` feature-test macro: `getline()` is only declared once it is
   defined (the Makefile adds `-D_GNU_SOURCE`).
4. `strcmp` sorts case-sensitively (`"van"` before `"Vasquez"`), and ignores
   accents. The 100-char fixed buffers overflow silently if a field is longer.
5. The CSV filename is hardcoded and must exist in the current directory.

### PHP / Chat One (security-relevant)

6. **Passwords are stored and compared in clear text** — see
   [SECURITY.md](SECURITY.md). The "check if a name already exists" logic reads
   the whole table row by row and is racy (two simultaneous registrations can
   both pass).
7. Messages are echoed unescaped into the page → stored XSS the moment a user
   posts `<script>`.

---

## Documentation

- [docs/BUILD.md](docs/BUILD.md) — building and running the C parts.
- [SECURITY.md](SECURITY.md) — security policy and the history of the data
  that was removed.
- [CONTRIBUTING.md](CONTRIBUTING.md) — working on this repository.
- [CHANGELOG.md](CHANGELOG.md) — version history.

## License

[MIT](LICENSE).
