#!/bin/sh
# Master Backup - A Master Solutions product
# 7/November/2024

export DATE=$(date)
COMMIT_MESSAGE="Auto Backup from Master Backup | ($DATE) |"

git add .
sleep 1
git commit -m "$COMMIT_MESSAGE"
sleep 1
git push
