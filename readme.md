# GitHub Commit History Booster

## Problem:
 - You know what you want: when you're browsing a LinkedIn or any other platform and you stumble across somebody's GitHub page and to your surprise you see a wall of green looking like my beginner's luck in stock trading the week before it all crashed
 - You want to be THAT guy (without actually being that guy)
 - You want to artificially inflate your ego by making it seem like you are inhumanly productive via your github commit history.
 - You want to start making results NOW

## Solution:
 - Use an automated system to spam commits in a repository under the guise of a crazy name (can be private or public doesn't matter however prefer private otherwise people will more easily tell what is going on haha) in which you have full access to commit directly to the main branch with no hiccups
 - Set the program exe to auto run on startup or at any interval throughout the day via OS Task Scheduler or both
 - Start ego profiting
 - Make sure to throw in some real work here and there to top it all off
 - Bonus points to do it in a private repo and have private repo commits show on your board so it looks like you're just grinding away at some special project

# Procedure:
 0. Create a new repository on GitHub Website preferably a private one!
 1. Go to the LOCAL Directory for where you will be creating your new repository
 2. Open CLI in this new directory
 3. Run these repository init commands to clone this repo into that directory:
 4. 

  `git clone https://github.com/SThompson-Void/GitCommitStatBooster`
  
  `git remote remove origin`
  
  `git init`
  
  `git remote add origin https://github.com/username/new-repo.git`
  
  -Add main.cc and readme.md to your gitignore file!
  
  `git add .`
  
  `git commit -m "Setup commit"`
  
  `git branch -M main`
  
  `git push -u origin main`
  

 5. Ensure there are no merge conflicts and you can push to github cleanly!
 6. Set your range of automated git commits on line [9] inside main.cc where designated
 7. --NOT NEEDED SINCE WE SET REMOTE ORIGIN IN ABOVE SETUP STEPS Set your new github repository URL on line [6] inside main.cc where designated-- 
 8. Compile main.cc, run the program, wait for final push to GitHub repo
 9. Check GitHub repo to see that contributions properly updated on your page
 10. Star the GitHub Commit History Booster Repo! (plz bro)
 11. Connect to OS Startup and Task Scheduler for program automation!
 12. Have fun!

 ## Future Plans?
 - Max optimization
 - Include automation for code reviews etc so activity history is more than just commits
