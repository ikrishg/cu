# CHRIST University Things (`cu`)

Coursework and lab submissions from **CHRIST University** — mostly C programming exercises and Web Application Development (WAD) static pages.

**Live hub (GitHub Pages):** [https://ikrishg.github.io/cu/](https://ikrishg.github.io/cu/)  
*(An older deploy may still be linked as [kkrishguptaa.github.io/cu](https://kkrishguptaa.github.io/cu/); this repo lives under [ikrishg/cu](https://github.com/ikrishg/cu).)*

## Layout

| Path | Course area | Contents |
|------|-------------|----------|
| [`c/`](c/) | C programming | Labs by module: examples, domain problems, algorithms, CIA |
| [`wad/`](wad/) | Web Application Development | Numbered assignments (`1`–`7`), each with `index.html` (and later labs add CSS/JS; lab 7 adds PHP/MySQL via Docker) |
| [`index.html`](index.html) | — | Browser-friendly navigation hub (same links as below) |

## C labs (`c/`)

Each exercise is a folder with `main.c` (or a named `.c` file under `4-algorithm/`). **Compile locally** — binaries are not stored in the repo.

```bash
cd c/2-examples/1
gcc main.c -o program    # or: gcc main.c && ./a.out
./program
```

| Folder | Description |
|--------|-------------|
| [`2-examples/`](c/2-examples/) | Introductory programs (folders `1`–`15`) |
| [`3-domain/`](c/3-domain/) | Domain-style problems (`1`–`10`) |
| [`4-algorithm/sequential/`](c/4-algorithm/sequential/) | Sequential algorithms (named source files, e.g. `1-swap-numbers.c`) |
| [`5-examples/`](c/5-examples/) | Additional examples (`1`–`5`) |
| [`6-cia/`](c/6-cia/) | CIA lab (bank account scenario) |
| [`7-examples/`](c/7-examples/) | More examples (`2`, `3`) |

See [`c/README.md`](c/README.md) for a full index of C exercises.

## WAD assignments (`wad/`)

Static HTML/CSS/JS pages. Open in a browser or via GitHub Pages:

- Hub: [ikrishg.github.io/cu/](https://ikrishg.github.io/cu/)
- Example: [ikrishg.github.io/cu/wad/1/](https://ikrishg.github.io/cu/wad/1/)

**Lab 7** (`wad/7/`) uses PHP and MySQL. Run with Docker from that folder:

```bash
cd wad/7
docker compose up --build
```

See [`wad/README.md`](wad/README.md) for per-assignment links.

## Contributing / notes

This is a personal coursework archive — not a maintained library. Source files (`.c`, `.html`, `.css`, images) are kept as submitted; layout and docs may change for clarity.
