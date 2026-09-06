# Build guide — the C components

Only the C parts need a compiler. The PHP chat and the Python sketch are
documented in the [README](README.md).

## Requirements

- `gcc` (or any C11 compiler)
- `make`
- **Only for `make game`:** SDL2 development headers
  (`libsdl2-dev` on Debian/Ubuntu, or install SDL2 via your package manager)

`getline()` needs a POSIX feature-test macro, so the CFLAGS add `-D_GNU_SOURCE`.

## `make records` — Tri d'étudiants

Builds `main.c` + `eleve.c` into `tri_eleves`:

```bash
make records
./tri_eleves
```

By hand:

```bash
gcc -std=c11 -Wall -Wextra -D_GNU_SOURCE main.c eleve.c -o tri_eleves
```

The program reads `Students.csv` **from the current working directory**, so run
it from the repository root (or wherever a copy of the CSV lives). It prints
every record, sorted by surname.

The build emits two warnings, both real defects kept on purpose rather than
silenced: the `sizeof`-on-a-pointer in `main.c:9` and the use of `getline()`.
See [README § Known limitations](README.md#known-limitations).

### Verified

Built and run with gcc 13.3 on Ubuntu 24.04 — exit 0.

## `make game` — Snack Game

Builds `icone.c` against SDL2 into `prog`:

```bash
make game
./prog
```

By hand (the command from the source header):

```bash
gcc icone.c $(sdl2-config --cflags --libs) -o prog
```

### Before running

`icone.c` loads its bitmaps from `quiz/` and `snack/` subfolders, which do not
exist in the repository — the images were uploaded flat to the root. Recreate
the layout described in `snack_C.txt` first:

```bash
mkdir -p quiz snack
mv image.bmp a.bmp c.bmp cible.bmp k.bmp n.bmp s.bmp titina.bmp tt.bmp quiz/
mv game_over.bmp pause.bmp play.bmp quitter.bmp "Black Mortal TTF Personal.ttf" snack/
```

### Not verified

SDL2 is not available in CI, and this code has not been compiled on a clean
Linux machine during this documentation pass. Treat `make game` as a starting
point, not a guarantee — report the first compile error you hit. The
assignment's own note (`snack_C.txt`) confirms `prog` was previously compiled
successfully on the author's machine.

## `make clean`

Removes `tri_eleves`, `prog` and any object files.

---

## What is deliberately not built

`prog`, the compiled game binary, was committed to this repository and is now
gitignored (see [SECURITY.md](SECURITY.md) and the `.gitignore` comments).
Always build from source.

The PHP and Python parts have no build step. `db.php` is created locally from
`db.example.php` and is gitignored — see the README.
