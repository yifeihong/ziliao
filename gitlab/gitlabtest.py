import gitlab
from datetime import datetime, timedelta

# GitLab URL and your personal access token
GITLAB_URL = 'http://121.41.164.152'
PERSONAL_TOKEN = 'glpat-w8FtMecC6C264iuHsqU9'

# Create a GitLab connection
gl = gitlab.Gitlab(GITLAB_URL, private_token=PERSONAL_TOKEN)

# Set the project ID or use project name to find it
PROJECT_ID = 123  # Replace with your project ID
# Alternatively, if you know the project path:
# project = gl.projects.get('group/project-name')

# Get the project
project = gl.projects.get('root/gitlabtest')

# Calculate the date one week ago
one_week_ago = datetime.now() - timedelta(days=7)

# Fetch all merge requests created in the last week
mrs = project.mergerequests.list(state='all', since=one_week_ago.isoformat())

# Iterate over each MR
for mr in mrs:
    print(f"Merge Request {mr.id} ({mr.web_url})")
    print(f"Title: {mr.title}")
    print(f"State: {mr.state}")
    print(f"Created at: {mr.created_at}")
    print(f"Updated at: {mr.updated_at}")
    print(f"Merged by: {mr.merged_by['name']}") if mr.merged_by else print("Not merged yet.")
    
    # Commit information
    commits = mr.commits()
    for commit in commits:
        print(f"Commit: {commit.id} - {commit.title}")
    
    # Comments information
    notes = mr.notes.list()
    print(f"Total comments: {len(notes)}")
    for note in notes:
        print(f"Comment by {note.author['name']}: {note.body}")
    
     # Get the full object to ensure all data is present
    full_mr = project.mergerequests.get(mr.id)
    # Now you can safely call methods like diff() on the full_mr object
    diffs_list = full_mr.diffs.list()
    print(f"Total diffs: {len(diffs_list)}")
    for diff in diffs_list:
        print(diff)

    # additions = sum([int(s['new_lines']) for s in diff_stats])
    # deletions = sum([int(s['deleted_lines']) for s in diff_stats])
    # print(f"Additions: {additions}, Deletions: {deletions}")

    print("-" * 80)