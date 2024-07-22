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


# 获取过去一周的日期范围
one_week_ago = datetime.now() - timedelta(days=7)

# 查询已合并的MRs
mrs = project.mergerequests.list(state='merged', since=one_week_ago.isoformat())

# 遍历MRs
for merge in mrs:
    # 获取完整的MR对象
    #full_mr = project.mergerequests.get(mr.id)
    
    print(f"Merge Request #{merge.iid} - Title: {merge.title}")  
    print(f"Merged At: {merge.merged_at}")  
        
    # 获取修改的代码行数  
    changes = merge.changes()  
    added_lines = 0  
    removed_lines = 0  
    # print(f"Changes: {changes}")
    for file in changes:  
        print(f"File: {file.changes_count}")
    #     added_lines += file['added_lines']  
    #     removed_lines += file['removed_lines']  
    # print(f"Added Lines: {added_lines}")  
    # print(f"Removed Lines: {removed_lines}")  
    # print(f"Total Modified Lines: {added_lines + removed_lines}")  
        
    # 添加分隔线，方便查看  
    print("-------------")  