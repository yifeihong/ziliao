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


# 获取过去一周的 MRs
one_week_ago = datetime.now() - timedelta(days=7)
mrs = project.mergerequests.list(state='all', since=one_week_ago.isoformat())


# 遍历 MRs
for mr in mrs:
    print(f'MR #{mr.iid}: {mr.title}')
    print(f'State: {mr.state}')
    print(f'Author: {mr.author["name"]}')
    print(f'Created at: {mr.created_at}')
    
    # 获取 MR 的 comments
    comments = mr.notes.list()
    print(f'Total comments: {len(comments)}')
    for comment in comments:
        if comment.author["name"] != 'Administrator':
            print(f'Comment by {comment.author["name"]} at {comment.created_at}:')
            print(comment.body)
            print('-' * 80)
        
    print('=' * 80)
    print()  # 添加一个空行以分隔不同的 MR