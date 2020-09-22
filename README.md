# ffmpeg
impotrant notes:
1)As much as i tried, i didnt manage to run ffmpeg, and get the result you presented  in the file:
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_start: 5.3053
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_duration: 2.05205
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_end: 7.35735
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_start: 16.78345    
...

after running: "ffmpeg -i freeze_frame_input_b.mp4 -vf "freezedetect=n=-0.003dB" -map 0:v:0 -f null -"
I got a result which shows only : "freeze_start"
I was trying about hour and a half to work it out - didnt manage to
I descided to create files which have the same output - parse them and create json file.
I managed to parse the files, but when i tried to print them to json file , I had a problem:
I arranged all the data such as : start and end times,longest valid periods, total aggregated persiods 
into three vector, and in order to print them to json i had to parse all the 3 at the same time,
it just didnt compile.
I searched in google and saw there is a library of boost for iterating more than one data structure
- it said ih have to use boose librarym somthing with zip. i didnt have any time left to install it
i wrote the task in c++. i know that python has a library for that(zip).
