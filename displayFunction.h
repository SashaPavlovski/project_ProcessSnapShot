#pragma once
char* displaySnapShotInTable(snapshot* snapShot_html, char* fileNameHtml, int countDLLInSnapHTML, SIZE_T sizeOfMemoryHTML);
char* displayProcessesInTitle(snapshot* snapShot_html);
char* displayProcessesInTable(snapshot* snapShot_html);
char* displayDLLSInProcess(PROCESS* snapShot_html);
