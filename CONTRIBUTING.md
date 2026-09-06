# Contributing to ProjetGit

ProjetGit is an archive of L2 coursework. It contains **three unrelated
projects** — the C CSV sort, the SDL2 game, and the PHP chat — plus loose files.
There is no common architecture. Before changing anything, decide which project
you are in and read its section of the [README](README.md).

This repository is public and has a history of real-data exposure. The two rules
below are absolute:

> **Never commit real personal data.** `Students.csv` is an anonymised fixture;
> it stays that way. Test with invented records.
>
> **Never commit database credentials.** PHP database access goes through the
> gitignored `db.php`, created from `db.example.php`.

---

## Setting up

```bash
git clone https://github.com/Heritina-sys/ProjetGit.git
cd ProjetGit
```

For the C parts you need `gcc` and `make`. The SDL2 game additionally needs SDL2
development headers. See [docs/BUILD.md](docs/BUILD.md).

For the PHP chat you need a PHP-capable server and MySQL, plus the layout
described in the [README § Chat One](README.md#3-php--chat-one) (`tpM/` + `StpM/`
folders, `Message` database).

---

## Before pushing

Run the same checks CI runs:

```bash
make clean && make records        # builds the C sort
./tri_eleves                      # exit 0
php -l chat.php tchat.php test.php traiterCompte.php   # syntax-check the PHP
```

and confirm:

- [ ] No real names, addresses, or phone numbers anywhere in the diff —
      including screenshots and comments.
- [ ] No credential added or changed in any tracked file. Only `db.example.php`
      is tracked; real values go in the gitignored `db.php`.
- [ ] No build output tracked (`prog`, `tri_eleves`, `*.o`) — `.gitignore`
      covers them.
- [ ] `Students.csv` unchanged, or replaced only by another anonymised fixture
      of the same shape (the C parser is brittle — see below).

---

## Conventions

This is student code. Keep your changes in the same spirit — clear and small —
but do not feel bound to preserve defects. The numbered list in
[README § Known limitations](README.md#known-limitations) is the honest map of
what is broken; fixing an entry is welcome and should be accompanied by deleting
or updating that line.

If you touch the C code:

- The CSV parser uses `getline`/`strtok` and fixed 100-char buffers. Note the
  off-by-one described in README limitation #1 before you "fix" the allocation
  arithmetic — the loop counts and bounds are coupled.
- `main.c` is compiled with `-D_GNU_SOURCE` (see the Makefile) because of
  `getline()`.

If you touch the PHP chat:

- **Passwords are still clear text.** Fixing this means `password_hash()` /
  `password_verify()` in `traiterCompte.php` and `test.php` — see
  [SECURITY.md](SECURITY.md). Do not add new code that reads or writes
  `Password` without hashing.
- Messages are echoed unescaped into `chat.php` (`echo $donne['message']`).
  Escape output if you touch that loop.
- All database access goes through the `db.php` handle provided as `$bdd`.

### Commits

One project per commit — do not mix the C and PHP trees in a single change.
[Conventional Commits](https://www.conventionalcommits.org/) style, imperative,
subject under 72 characters:

```
fix(chat): hash passwords before storing them
fix(c): guard the CSV record loop against reading past the allocation
docs: add README and SECURITY.md
```

---

## The PHP chat is a teaching exercise, not a product

It has no security model worth preserving: clear-text passwords, no CSRF
protection, no escaping, session-only state. Before investing in it, consider
whether the effort belongs in the [ZKAPI](https://github.com/Heritina-sys/ZKAPI)
platform instead — the same *"Chat One"* idea was rebuilt several times in this
account's repositories.

## Especially welcome

- Hashing passwords (`password_hash` / `password_verify`).
- Escaping chat output.
- Removing the dead `verification_nom.php`/`security.php` redirect noise, or
  explaining what it was for.
- Fixing the C off-by-one and the `sizeof`-on-pointer line in `main.c`.
- A CI job that builds the SDL2 game once SDL2 is available.
- Sorting that matches how French names are actually compared (accents, case,
  `d'`).

## Reporting

- **Bugs and features** — [open an issue](https://github.com/Heritina-sys/ProjetGit/issues/new/choose).
- **Security** — do not use the issue tracker. Follow [SECURITY.md](SECURITY.md).
