# AutoShell
not open-source; but an epic command-line tool for easy use;
## Simplistic
AutoShell has already a fast environment, downloading 10MB's and extracting it in 10 SECONDS!!!<br>(depends on wifi speed, but the extraction speed is CRAZY!!!)
## Script-Language
AutoShell Script (ASS) is a Scripting Language powered by the AutoShell environment based on BATCH.<br>Example Script (such as downloading Celery):
```
-- Celery Installer Script (celery.ass)
@echo off
cd ../../../
mkdir Celery
@echo on
echo Created Celery Folder
@echo off
webdl https://github.com/static-archives/Celery/raw/main/Release.zip Celery.zip
@echo on
echo Celery.zip Installed
@echo off
unzip Celery.zip Celery
@echo on
echo Installed Celery
@echo off
-- Celery installed!
```
## Auto-Updater
Everytime you open up AutoShell, the Updater opens to check for an update, or if the program has registered the .ass extension!<br>This is helpful, because I plan on adding updates to AutoShell!
## Batch Environment & ASS Environment
AutoShell can run .bat and .ass files, go ahead drag and drop one, or run start <name>!
