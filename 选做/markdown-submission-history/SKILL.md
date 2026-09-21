---
name: markdown-submission-history
description: Prepare and submit Markdown coursework while preserving a concise, repository-visible record of each new .md submission. Use when adding or revising Markdown assignment files in this project.
---

# Markdown Submission History

Use this skill for Markdown coursework submitted to this repository.

## Submission workflow

1. Keep the assignment's original filename and save it as a UTF-8 `.md` file at the repository root unless the task specifies another location.
2. Before committing a new Markdown file, update `选做/markdown-submission-history/CHANGELOG.md` with one new entry. Record the date, filename, a short topic summary, and the main learning or writing elements added.
3. Check that the document has one meaningful top-level title, a readable heading hierarchy, fenced code blocks with language labels where applicable, and source links for externally referenced material.
4. Commit the Markdown file and its changelog update together. Use a short message that identifies the submission, such as `Add Linux command practice`.

## Practice-report additions

For command-practice reports, give each command or task its own third-level heading. State the command, its purpose, the observed result, and any environmental limitation or correction. Preserve useful caveats such as shell built-ins not being located by `which`, prerequisite files for examples, permission boundaries, and differences between WSL and a full Linux system.

## Record boundaries

The changelog is an index of Markdown submissions, not a copy of the coursework. Do not alter older entries when adding a later submission unless correcting a factual mistake.
