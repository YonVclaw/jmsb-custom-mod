# Setting up a jmfsb mission

**The mission maker's guide is the [wiki](https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER/wiki).**

It covers installation, the smallest mission that boots, every config file, the
cross-file contracts nothing validates for you, and a troubleshooting table.

| | |
|---|---|
| [Installation](https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER/wiki/Installation) | What you need loaded |
| [Mission Setup](https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER/wiki/Mission-Setup) | The smallest mission that boots |
| [How Config Loads](https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER/wiki/How-Config-Loads) | The two paths in |
| [Config Reference](https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER/wiki/Config-Reference) | Every config file |
| [Cross-File Contracts](https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER/wiki/Cross-File-Contracts) | The pairs that must agree |
| [Troubleshooting](https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER/wiki/Troubleshooting) | Symptom → where to look |

It lives on the wiki and not in `docs/` because `docs/` is the **mod's** own
reference — generated from the addon sources by `tools/gen_docs.py` — while the
wiki is written for people building missions on the framework, who are not
necessarily reading the repository at all.

---

## Maintaining the wiki

A GitHub wiki is a **separate git repository**. The source of truth for it is
`wiki/` **in the DIVINER repo**, not this one - the framework mission and
DIVINER go together, and the wiki documents that pair. It moved there on
2026-09-03.

To publish changes:

```sh
# once, from the DIVINER repo
git clone https://github.com/Joint-Multi-Functional-Strike-Battalion/DIVINER.wiki.git ../DIVINER.wiki

# each time
cp wiki/*.md ../DIVINER.wiki/
cd ../DIVINER.wiki
git add -A
git commit -m "wiki: <what changed>"
git push
```

### Conventions

- Pages are **flat** — no folders. A file called `Comms-Plan.md` becomes the page
  **Comms Plan** at `/wiki/Comms-Plan`.
- `Home.md` is the landing page. `_Sidebar.md` is the navigation shown beside
  every page. `_Footer.md` is the footer.
- Link between pages with `[Comms Plan](Comms-Plan)` — the file name without the
  extension. Anchors work as `[Admins](Other-Systems#admins)`.
- Every page must be reachable from `_Sidebar.md`.
