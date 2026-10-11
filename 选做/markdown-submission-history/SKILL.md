---
name: markdown-submission-history
description: Prepare and submit Markdown coursework while preserving a concise, repository-visible record of each new .md submission. Use when adding or revising Markdown assignment files in this project.
---

# Markdown Submission History

Use this skill for Markdown coursework submitted to this repository.

## Submission workflow

1. Keep the assignment's original filename and save it as a UTF-8 `.md` file at the repository root unless the task specifies another location.
2. Before committing a new Markdown file, update `选做/markdown-submission-history/CHANGELOG.md` with one new entry. Record the date, filename, a short topic summary, and the main learning or writing elements added.
3. Check that the document has one meaningful top-level title, a readable heading hierarchy, fenced code blocks with language labels where applicable, and source links for externally referenced material. Embed experiment screenshots with repository-relative paths and captions stating what each image shows.
4. Commit the Markdown file and its changelog update together. Use a short message that identifies the submission, such as `Add Linux command practice`.

## Practice-report additions

For command-practice reports, give each command or task its own third-level heading. State the command, its purpose, the observed result, and any environmental limitation or correction. Preserve useful caveats such as shell built-ins not being located by `which`, prerequisite files for examples, permission boundaries, and differences between WSL and a full Linux system.

For assembly experiments, connect each relevant source statement to the generated instructions. Trace parameters, return addresses, saved frame pointers, stack space, and return values through calls and returns. Distinguish what screenshots show from what follows from the calling convention.

When the assignment requires both Markdown and PDF, generate the PDF from the completed Markdown and inspect its pages before committing. Keep the two versions in sync and record the new Markdown submission in the changelog.

## Record boundaries

The changelog is an index of Markdown submissions, not a copy of the coursework. Do not alter older entries when adding a later submission unless correcting a factual mistake.

## Integrated coursework and exemplar improvements

For an assignment that combines an experiment with textbook or video learning, keep a standalone experiment report when requested, and include its full analytical content at the beginning of the main assignment. Remove repeated signature and attribution introductions from the embedded copy; retain one top-level title per document. Verify the textbook's actual chapter title, section headings, page range, and software version before outlining the learning report.

When a provided exemplar improves the report, adopt its useful structure without copying its authorship, screenshots, or personal experience. For kernel mechanism reports, use this presentation order: complete, file-labelled teaching code; experiment results and screenshots immediately after the source blocks; then code analysis of initialization, data structures, interrupts, scheduling, and context restoration. Keep screenshots together near the start of the report, before extended command explanations or line-by-line mechanism analysis. Apply the same order to the standalone experiment report and the experiment content embedded in the assignment. Pin the source version; preserve attribution and identify any learning edits.

Analyze both first execution and resuming a suspended task. For time-slice examples, cover a forward transition such as 0 to 1 and a wraparound transition such as 3 to 0; connect register changes, saved stack contents, continuation labels, and log ordering. Distinguish an interrupt requesting scheduling from the point where switching actually occurs. Explain architecture and compiler assumptions rather than presenting a teaching example as production kernel code.

Center the learning report on concrete questions, causes, solutions, and supporting evidence. Cover the assigned textbook and video topics separately. Use operational records for observed results and clearly labelled execution diagrams or theoretical output for source-derived behavior; do not invent execution logs, troubleshooting history, or video timestamps.

On each new coursework submission, review the current skill against the task and any supplied exemplar, add only improvements supported by that use, and record the submission plus skill changes in the existing changelog. Preserve previous entries.

When separate experiment and assignment PDFs are requested, export each from its corresponding final Markdown. Check Chinese fonts, code wrapping, tables, screenshots, page breaks, and source links. Validate repository-relative assets and internal links before submitting all requested outputs, assets, skill changes, and the new changelog entry together. Exclude textbook PDFs and temporary conversion files.
