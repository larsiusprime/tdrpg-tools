del bin\_output\locales\en-US\scenes.tsv
copy bin\_output\locales\en-US\scenes_lorem.tsv bin\_output\locales\en-US\scenes.tsv
robocopy bin/_output/xml ../../DefendersQuest2/assets_preprocess game_progression.xml
robocopy bin/_output/xml ../../DefendersQuest2/assets/demo/xml scenes.xml
robocopy bin/_output/locales ../../DefendersQuest2/assets/demo/locales *.* /E
robocopy bin/_output/scenes ../../DefendersQuest2/assets/demo/xml/scenes *.* /E
robocopy bin/_input ../../DefendersQuest2/_script *.* /E
pause