
# AI Prompt Log and Development Process

## Project: AI Bug Report Assistant
Course: COSC 4272 Senior Seminar

## Overview

During the development of the AI Bug Report Assistant,
I used ChatGPT to help plan, implement, deploy, debug,
and document my application.

I used Google Gemini as the AI model that analyzes
software bugs submitted by users.

The entries below summarize the main AI-assisted
development interactions. They are descriptions of
the conversations rather than verbatim prompt transcripts.

## Entry 1: Project Planning

AI Tool: ChatGPT

Task: Determine how to fulfill the AI assistant
requirement for my Senior Seminar portfolio.

AI Assistance:
ChatGPT recommended creating an AI Bug Report Assistant
using Python, Streamlit, and Google's Gemini API.

Outcome:
I selected the project because it relates to software
development, debugging, and programming.

## Entry 2: Building the Interface

AI Tool: ChatGPT

Task: Develop the initial Streamlit application.

AI Assistance:
ChatGPT provided Python code for a bug-description
text box, programming language dropdown, and
Analyze Bug button.

Outcome:
I created app.py, uploaded it to GitHub, and
verified that the interface worked.

## Entry 3: Application Deployment

AI Tool: ChatGPT

Task: Deploy the Python application online.

AI Assistance:
ChatGPT guided me through creating requirements.txt
and configuring Streamlit Community Cloud.

Outcome:
I successfully deployed the application and
confirmed that it was accessible in a browser.

## Entry 4: Gemini API Integration

AI Tool: ChatGPT

Task: Connect the application to an AI model.

AI Assistance:
ChatGPT explained how to create a Gemini API key,
store it using Streamlit Secrets, install the
google-genai library, and modify app.py.

Outcome:
The application was able to send bug descriptions
to the Gemini API.

## Entry 5: Troubleshooting an API Error

AI Tool: ChatGPT

Actual prompt:
"its been analyzing for almost 2 minutes now.
is it supposed to take this long?"

Problem:
The application was not returning an AI response.

AI Assistance:
ChatGPT suggested checking Streamlit's application
logs and adding exception logging to identify the
underlying error.

The logs showed an HTTP 503 error indicating that
the selected Gemini model was experiencing high demand.

Outcome:
I changed the Gemini model to Flash-Lite and tested
the application again. It successfully generated
a debugging report.

## Entry 6: Documentation and Portfolio Integration

AI Tool: ChatGPT

Task: Present the completed application professionally.

AI Assistance:
ChatGPT helped me add the live application URL
and GitHub source code link to my portfolio.
It also helped structure the project README.

Outcome:
The project is now accessible through my
GitHub Pages portfolio.

## Reflection

AI-assisted development helped me organize the
project and troubleshoot problems more efficiently.

However, I still had to create the repository,
configure the hosting services, manage the API
key, test the application, examine the error logs,
and verify that the suggested changes worked.

One important lesson was that AI-generated code
does not automatically guarantee that an application
will work correctly. Testing and troubleshooting
are still necessary.

## Security

The Gemini API key is stored privately in
Streamlit Secrets. The key is not included
in this documentation or the public source code.
