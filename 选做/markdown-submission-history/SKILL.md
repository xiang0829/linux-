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

For submission of existing user-supplied reports, preserve the finished Markdown and PDF contents. Check the PDF pairings and repository-relative image references, and upload the requested reports plus their referenced images while retaining relative subdirectories. Map a duplicated local wrapper folder to the single repository folder named by the user. Include separate source files or build artifacts only when requested or linked as required attachments.

## Practice-report additions

For command-practice reports, give each command or task its own third-level heading. State the command, its purpose, the observed result, and any environmental limitation or correction. Preserve useful caveats such as shell built-ins not being located by `which`, prerequisite files for examples, permission boundaries, and differences between WSL and a full Linux system.

For assembly experiments, connect each relevant source statement to the generated instructions. Trace parameters, return addresses, saved frame pointers, stack space, and return values through calls and returns. Distinguish what screenshots show from what follows from the calling convention.

When the assignment requires both Markdown and PDF, generate the PDF from the completed Markdown and inspect its pages before committing. Keep the two versions in sync and record the new Markdown submission in the changelog.

## Record boundaries

The changelog is an index of Markdown submissions, not a copy of the coursework. Do not alter older entries when adding a later submission unless correcting a factual mistake.

## Integrated coursework and exemplar improvements

For an assignment that combines an experiment with textbook or video learning, keep a standalone experiment report when requested, and include its full analytical content at the beginning of the main assignment. Keep one signature, originality statement, and course attribution for the whole assignment; remove only duplicate introductions from its embedded experiment. Retain one top-level title per document. Verify the textbook's actual chapter title, section headings, page range, and software version before outlining the learning report.

When a later week reuses an earlier experiment, follow the explicitly requested experiment number rather than inferring a replacement from the week or textbook chapter. Preserve its full analytical body and screenshots, while rebuilding the integrated title and chapter-specific references. Keep textbook demonstration values and proposed validation methods distinct from the student's operational records; organize AI-assisted learning around questions and checked answers rather than invented dialogue or new execution logs.

When a provided exemplar improves the report, adopt its useful structure without copying its authorship, screenshots, or personal experience. For kernel experiment reports, open with the actual short setup/run command block, then briefly explain relevant directories and file roles. Introduce early results with a short mechanism analysis; explain each operation and result before its screenshot, followed by a factual caption. Place extended source analysis later instead of collecting consecutive images without explanations. Apply the same structure to standalone and embedded experiment reports. For the mykernel report, “实验源码” refers to the supplied setup/run shell commands, not full C files; do not carry its exact commands or file names into different experiments. Pin source versions, preserve attribution, and identify learning edits.

For kernel boot tracing, distinguish the reset stop, generic initialization, task creation, exec preparation, and actual user-mode execution. Explain bzImage versus vmlinux and the QEMU pause/debug options. Separate PID 0's idle path from PID 1's kernel_init/exec path; task creation is not an ordinary direct function call. Use only identifiable stack frames and corroborate incomplete backtraces with source. Keep observed course-tree line numbers separate from upstream version references.

For system-call learning, separate library APIs, architecture ABIs, entry/exit code, and service handlers. Verify registers, call numbers, and hardware-versus-software context saving for each architecture; distinguish privilege transitions from task switches. When the user excludes video work, omit the video section rather than adding assumed viewing records.

Analyze both first execution and resuming a suspended task. For time-slice examples, cover a forward transition such as 0 to 1 and a wraparound transition such as 3 to 0; connect register changes, saved stack contents, continuation labels, and log ordering. Distinguish an interrupt requesting scheduling from the point where switching actually occurs. Explain architecture and compiler assumptions rather than presenting a teaching example as production kernel code.

Center the learning report on concrete questions, causes, solutions, and supporting evidence. Cover the assigned textbook and video topics separately. Use operational records for observed results and clearly labelled execution diagrams or theoretical output for source-derived behavior; do not invent execution logs, troubleshooting history, or video timestamps.

On each new coursework submission, review the current skill against the task and any supplied exemplar, add only improvements supported by that use, and record the submission plus skill changes in the existing changelog. Preserve previous entries.

When the user requests a batch with one final skill update, finish and check all reports first, then make one shared skill revision and one changelog entry listing the batch. For a summary report, link to the actual submitted reports and provide a short reading introduction for each; do not substitute local source-material paths or invent earlier experiment titles.

When supplied notes and screenshots disagree, verify numeric results against the original images and the matching source version. Distinguish executable architecture from syscall ABI, service-handler breakpoints from hardware entry, and task-construction fields from final process identity. Explain fork, exec, privilege transitions, and task switches separately; yield does not guarantee alternation. State the exact instruction boundary required for stack-pointer comparisons. Preserve original test attachments and identify corrections to comments or proposed improvements in the analysis rather than presenting them as executed results.

When separate experiment and assignment PDFs are requested, export each from its corresponding final Markdown. Check Chinese fonts, code wrapping, tables, screenshots, page breaks, and source links. Validate repository-relative assets and internal links before submitting all requested outputs, assets, skill changes, and the new changelog entry together. Exclude textbook PDFs and temporary conversion files.

## Task-requirement audit

Before drafting or revising reports, map every task-page requirement to a specific report section. Check publication requirements separately from technical analysis: explicitly name the actual author as “真实姓名”, include “原创作品转载请注明出处”, and provide the named MOOC course with its exact clickable URL when required. A course link in references alone does not replace the originality statement. Verify both standalone reports and integrated assignments, including their exported PDFs; retain already-compliant documents without unnecessary rewriting. Submit to course platforms only when separately authorized.

Check task-specific conclusions and diagrams as well as headings: generalize system-call handling to ordinary interrupts when required; explain first execution and saved kernel/user stack layouts for fork and exec; relate scheduling to Linux's general execution process. For a final learning summary, index every actual experiment by number, add a useful introduction and current assignment links, and cover both gains and regrets. Preserve original observations and assets; label source-derived diagrams as mechanism illustrations. After a batch audit, make one shared skill revision and one changelog entry, with a concise requirement-to-report checklist when useful.
