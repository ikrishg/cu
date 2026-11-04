# Writing style

Three voices. Pick by surface.

1. **Site / identity:** short, poetic, spare ([krishg.com](https://krishg.com), GitHub profile).
2. **Product README:** clear, tradeoff-honest, lightly branded (Panasch, Verstappen, Starspect, Tastebuds, Dockyard, Orpheus, Reseter.css, github-liege).
3. **Blog / DEV / social:** first-person, memey, argumentative, bilingual asides (Hashnode/DEV "Let's Crack Open Open Source").

Coursework folder READMEs in `cu` sit between 1 and 2: narrative first, then a numbered index table, then `← Back to …`.

## Identity voice

From the site and profile:

- "I'm Krish. I build stuff."
- "Making and hacking. Dabbling with the frontier. Leaving a poetic imprint."
- "perfectionist overkill engineer & poet"
- Glitter is refused on purpose.

Rules:

- Short sentences. Fragments allowed when they land like poetry.
- No widget farms, trophy shelves, or fake busy dashboards in about pages.
- Contact and craft over personality quizzes.

## Product README voice

Patterns that repeat across his repos:

- Open with what it is in one breath, then the sharp constraint ("zero-runtime-dependency", "verify authenticity of GitHub stars", "One line AI-generated description…").
- Centered logo + one-liner is fine for product repos (Tastebuds, Dockyard, Reseter). Profile and sparse tools stay text-only.
- **Why not X** sections when the design is a refusal (Panasch vs Pino/Winston).
- Tables for options, support matrices, env vars, Notion properties.
- Numbered local run steps. Sometimes `1.` repeated (Tastebuds/Dockyard) as a list habit; either form is fine.
- Status sections that admit unfinished work.
- Personal "Why did I make this?" when the product has a story (Tastebuds vs Spotify lockout, rewrite in Solid).
- Orpheus blends engineer docs with poet manifesto: "What is the world but a collection of words?" then ISR and `cwebp` in the same README. That mix is allowed on poetry-adjacent projects.
- License note can separate code license from poem copyright.
- Emoji in headings appears in some READMEs (Orpheus, older posts) and is absent in newer sparse ones (Starspect, Verstappen, liege). Prefer sparse for new infra docs; emoji OK for playful apps.

### Course README voice (`cu`)

From AGENTS preferences and current course docs:

- Lead with the domain story, not a file inventory.
- Still ship a numbered topic table for labs and assignments.
- End subdirectory READMEs with `← Back to <parent>`.
- Root index is a semester table of courses.

## Blog / essay voice

Canonical sample: [Let's Crack Open "Open Source"](https://dev.to/kkrishguptaa/lets-crack-open-open-source-2n45) (also Hashnode).

- Opens on a cultural beat (tech Twitter takes), not a textbook definition.
- Book definition vs "actual definition" contrast.
- Short answer / long answer pairs.
- Self-owns the bit ("Okay, I admit that the last one is just me", homemade bad memes).
- Hindi / Hinglish punchlines with a quick translation when needed ("Yeh Sab Doglapan Hai!").
- GIFs and embeds are part of the argument, not decoration only.
- Direct challenge to the reader ("What in the damn world can stop you…").
- Checklists when teaching steps (first PR).
- Soft ask for feedback mid-article.
- Signs off warm and slightly chaotic ("If you love me content… memey content").

Use this voice for blog posts and talk writeups. Do not paste it into library API docs.

## Hobbit / coursework product copy

From `csc161-1` HTML:

- Strong opinions in plain words ("extinguish larpers in the age of AI").
- Self-intro that stacks facts: introvert, writes poetry, points at the site.
- Visual play (huge rotated marquee, editorial serif) without long marketing paragraphs.

## Commit messages

- Serious repos: Conventional Commits (`docs:`, `refactor:`, `ci:`, `chore(deps):`) plus a body that explains why.
- Casual course saves: terse lowercase (`lab 5`, `wad proj`) when he is dumping work himself.
- Agent-assisted commits on his repos still read as why-first conventional messages.

## Words and habits

- Prefers concrete nouns and named tools over abstract "solutions landscape" talk.
- Will say the quiet part: what is missing, what is slower, what Spotify broke.
- Brand names are coined and sticky; descriptions stay one line.
- Poetry and engineering can share a page when the project is about poems.

## Looks not like him

- Corporate blog tone ("In today's rapidly evolving…").
- README that only lists folders with no story.
- Fake completeness ("production-ready" on a scaffold).
- Profile-style widget spam.
- Course docs that open with build commands instead of what the thing is about.
- Stripping all personality from Tastebuds-class apps, or dumping meme voice into Panasch API reference.

## Quick fingerprint checklist

- [ ] Right voice for the surface?
- [ ] One-line what + sharp constraint up top for products?
- [ ] Tradeoffs or unfinished status said out loud?
- [ ] Course README: narrative, then index, then back-link?
- [ ] Blog: first person, argument, room for a joke?
- [ ] No glitter on surfaces that chose silence?
