# Coding style

Two registers. Same person. Do not mix them by accident.

1. **Coursework C** in `cu` (labs, assignments, short console programs).
2. **Shipped TypeScript / web** on GitHub (libraries, apps, tooling).

If the file is for a CHRIST submission, use register 1. If it is a real product or library under `ikrishg`, use register 2.

## Opinions that show up everywhere

- **Intentional minimalism.** Profile README: "Lack of widgets/other github readme glitter is intentional." Prefer a small surface that does one job well (Reseter.css, Panasch "no worker threads", Starspect stating what is not built yet).
- **Overkill where it matters.** Size limits, cancel failed bodies, typed overloads, redact defaults, CI that typechecks. Perfectionism lands on edges and failure modes, not on decorative abstractions.
- **Honest tradeoffs.** Panasch publishes benchmarks where it loses to Pino and says why anyway. Do not hide numbers that make the choice look worse.
- **Domain glue for school work.** One world per course folder (wildlife census, Hobbit, Kwish Swiss Bank). Programs share names and story, not only syntax topics.
- **Flat, descriptive filenames.** `population_pointers.c`, `animal_records.c`, not `lab7/main.c`. No personal name or register number in filenames.
- **Compress assets.** WebP for images, strip identity from exports, dedupe shared gallery files. Prefer shipping small binaries.
- **No surprise headers in coursework.** Course C stays single `.c` files unless the brief forces `.h`. Shipped TS uses real modules and exports.
- **Playful names, serious insides.** Verstappen, Panasch, Tastebuds, Dockyard, Orpheus, Starspect, Azelf. The code under the name is typed and blunt.

## Register 1: coursework C

Canonical samples: `csc101-1/lab/population_*.c`, `wildlife_census.c`, `animal_records.c`, `csc101-1/project/bank.c`.

- 2-space indent in the polished labs. Some older or denser files use 4 spaces (`animal_records.c`). Match the nearest sibling file in the same folder.
- `#include <stdio.h>` (and friends) only. No custom headers for assignments unless required.
- `int main() {` with no `void`.
- Declare locals at the top of the block in classic style when the file already does (`int i, j;`). Newer lab files may use `for (int i = 0; ...)`. Stay consistent inside one file.
- Banner titles with `===== TITLE =====` and section rules with `----- Section -----`. Align colon labels in report lines (`"Total Population  : %d\n"`).
- Input validation with a `do { ... } while` when bounds matter.
- Menu loops: `do { printf choices; scanf; if / else if } while (choice != exit)`.
- Pointer arithmetic when the topic is pointers (`*(population + i)`). Plain `a[i]` when the topic is structures and the sibling labs do that.
- Short comments only when they mark a concept the lab is teaching (`/* Global variable */`, `/* Passing values to user-defined functions */`). No essay headers.
- Prompt text is plain and instructional: `"Enter number of species (1-10): "`, `"Invalid input. Enter a value between 1 and 10.\n"`.
- One program, one concept, still inside the shared domain.
- Group project UI can be louder (ASCII box art in `bank.c`). Solo labs stay quieter.

### Looks wrong for course C

- Separate `.h` for a five-question sheet when nothing else in the repo uses them.
- Generic `Student` / `Book` domains when the folder already has a story world (unless the brief names those structs).
- Heavy defensive coding, custom allocators, or framework patterns.
- Emoji in source, markdown in comments, or AI banner walls.

## Register 2: shipped TypeScript and web

Canonical samples: `panasch` (`src/logger.ts`, sinks, context), `verstappen` (`src/index.ts`), Starspect, Tastebuds, Dockyard, github-liege, Reseter.css.

- TypeScript-first. Explicit exported types. Overloads when return type depends on options (`azelf` file vs buffer).
- Prefer Standard-style spacing: space before `(` in function declarations (`export function createLogger (options: LoggerOptions = {}): Logger`).
- Small focused modules (`sink.ts`, `redact.ts`, `serialize.ts`). Re-export from a thin `index`.
- `node:` protocol imports where Node-specific (`node:fs`, `node:stream`).
- Defaults that are safe (`DEFAULT_REDACT_PATHS`, download size caps). Never throw from a logger path if you can avoid it.
- Document what you refuse to support in a table next to what you support (Panasch Pino compatibility).
- Package managers vary by repo (`pnpm`, `bun`, `yarn`, `npm`). Follow the repo in front of you; do not rewrite the toolchain for style.
- Prefer Bun or pnpm on newer apps when starting greenfield under his brand, but matching an existing lockfile wins.
- CSS resets and classless / semantic HTML instincts (Reseter.css, pikoto.css pitch). Course Hobbit pages reuse Reseter from CDN.
- Status honesty in READMEs: "Early scaffold. The verification logic is not written yet." beats fake completeness.
- Monorepo filters and workspace scripts when there are multiple packages (`pnpm --filter ./extension`).

### Looks wrong for shipped code

- Course-style `=====` banners inside library source.
- Silent omission of known limits.
- Giant god-files when the project already splits by concern.
- Adding README badge glitter to repos that chose sparse intros (profile, Starspect, Verstappen).

## Commits

Two modes appear in history:

1. **Casual course dumps:** `lab 4`, `wad proj`, `put *.out in gitignore`.
2. **Conventional, why-first:** `docs: …`, `refactor: …`, `ci: …`, `chore(deps): …` with a short body that names the reason.

For anything agent-written or destined for `main` on a serious repo, use mode 2: type prefix, imperative summary, body that says why. Keep course dump mode only when he is clearly doing quick local saves himself.

## Quick fingerprint checklist

Before calling code "his":

- [ ] Right register (course C vs shipped TS)?
- [ ] Filename flat and descriptive?
- [ ] Surface small; edges overkill?
- [ ] Tradeoffs stated if README-adjacent?
- [ ] No coursework headers unless required?
- [ ] Domain continuity in `cu` folders?
