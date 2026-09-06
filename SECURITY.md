# Security policy

## Reporting a vulnerability

Report privately — **do not open a public issue.**

Use GitHub's private vulnerability reporting:
[**Report a vulnerability**](https://github.com/Heritina-sys/ProjetGit/security/advisories/new).
If unavailable, contact the maintainer via their
[GitHub profile](https://github.com/Heritina-sys).

Include the affected commit, reproduction steps, and what an attacker gains.
First response within 7 days.

## Supported versions

| Version | Supported |
|---|---|
| `main` (unreleased) | ✅ |

This is an archive of student coursework, not a deployed product. The policy
below exists because real incidents happened in this repository, not because it
is a production service.

---

## Real personal data was public here for two years

`Students.csv` was a list of **41 real students** — surname, first name, date of
birth, **home address**, phone number, gender and programme. It was committed in
2024 and this repository is public, so the file — and every previous version of
it — was downloadable by anyone until it was replaced by an anonymised fixture in
September 2026.

Replacing the file in the current tree is **not** remediation:

- Every past commit still contains the real records. Anyone who cloned the
  repository before the replacement has them forever.
- A purge of the history (`git filter-repo` or equivalent, followed by a
  force-push) would remove the file from future clones, but **cannot undo the
  two years of exposure** and would rewrite every commit hash.

**What you should do:**

1. Treat the affected people's data as compromised. If these records were
   collected for a real purpose (a school, a company), tell whoever is
   responsible for them what was exposed and for how long. Under GDPR-style law
   this is likely a reportable personal-data breach.
2. Decide with the data owner whether to purge the git history. It does not fix
   the exposure, but it stops the file being handed to every new visitor.

The anonymised replacement preserves the exact shape of the file (same header,
same 41-record count, same `\n` layout) so the C program that parses it behaves
identically. The fixture is fictional; do not reintroduce real data.

## The PHP chat stored passwords in clear text

Every account in "Chat One" stored its password in a `Password` column as plain
text, and login compared `$_POST['password'] == $pass['Password']` directly.
Compromising the database (or reading a backup) disclosed every password.

As of September 2026 the code is still clear text — no hashing has been added.
**Do not use this chat for anything real**, and do not reuse a real password in
it. This is fixed only by moving to `password_hash()` /
`password_verify()`, which is a code change, not a documentation one.

## The PHP chat embedded database credentials in source

Four files originally contained the connection string inline:

```php
$bdd = new PDO('mysql:host=localhost;dbname=Message', 'root', 'h');
```

Username `root` and password `h`, committed and public since 2024. Every past
commit still contains them.

As of September 2026 the code requires `db.php` instead (gitignored, template in
`db.example.php`). **If that `root`/`h` account ever existed on a reachable
MySQL server, change or remove it** — assume the credentials are public.

## Other PHP weaknesses

- Passwords and messages travel in clear text unless the server is HTTPS.
- No CSRF token on any form; login is session-based with no session hardening
  (`session.cookie_httponly`, `session.use_strict_mode`, etc.).
- Chat messages are echoed unescaped into the HTML — a stored-XSS hole.
- No rate limiting on login or account creation.
- The old failure mode echoed `$e->getMessage()` to the browser (database
  details, host, driver versions). `db.example.php` uses `error_log` instead.
- `verification_nom.php` / `retest.php` / `security.php` disclose *whether* a
  name or password is correct; combined with unthrottled login this enables
  username enumeration.

## C program

- Reads whatever file is named `Students.csv` in its working directory. Do not
  point it at a real dataset — that is exactly how the PII incident started.
- The CSV-parsing loops and `qsort` comparator have the buffer and bounds issues
  listed in [README § Known limitations](README.md#known-limitations). This is
  student code, not code to feed untrusted input.

---

## Scope of this policy

In scope: remaining data exposure in the current tree, the clear-text password
flow, and the clear-text (HTTP) transport if this is ever deployed.

Out of scope: code style, and re-litigating the incidents above — they are
documented so the fixes make sense, not to solicit commentary. Report *new*
findings.
