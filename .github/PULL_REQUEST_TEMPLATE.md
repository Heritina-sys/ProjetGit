<!--
Thanks for contributing. One project per PR — the repo mixes a C program, an
SDL2 game and a PHP chat. Say which one this changes.
Conventions: CONTRIBUTING.md
-->

## Project

- [ ] C — Tri d'étudiants (`main.c` / `eleve.c` / `eleve.h`)
- [ ] SDL2 game (`icone.c`)
- [ ] PHP — Chat One (`*.php`, `*.css`, `db.example.php`)
- [ ] Python — `snack.py`
- [ ] Documentation / tooling (README, docs, Makefile, CI)

## What this changes

<!-- One or two sentences. What is different after this merges? -->

## Why

<!-- Link the issue if there is one: Closes #123 -->

## How to check it

<!--
The steps a reviewer follows. For C: make records && ./tri_eleves. For PHP:
php -l on the changed files, then whatever you verified by hand.
-->

## Checklist

- [ ] No real personal data anywhere in the diff (names, addresses, phones) —
      including screenshots and code comments
- [ ] No credential committed — `db.php` stays gitignored; only
      `db.example.php` is tracked
- [ ] `make clean && make records` passes (C changes)
- [ ] `php -l` passes on changed PHP files (PHP changes)
- [ ] No build output tracked (`prog`, `tri_eleves`, `*.o`)
- [ ] `Students.csv` unchanged, or replaced only by another anonymised fixture
      of identical shape
- [ ] Known-limitation list in `README.md` updated if you fixed one

## Notes for the reviewer

<!-- Anything you are unsure about, or deliberately left out of scope. -->
