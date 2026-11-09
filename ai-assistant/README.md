
# AI Bug Report Assistant

## Project Overview

The AI Bug Report Assistant is a web application designed
to help programmers troubleshoot software bugs using
artificial intelligence.

Users can describe a programming problem, select a
programming language, and receive AI-generated debugging
suggestions.

This application was developed as part of my COSC 4272
Senior Seminar professional portfolio project.

## Technologies Used

- Python
- Streamlit
- Google Gemini API
- Google Gen AI Python SDK
- Git and GitHub
- Streamlit Community Cloud

## Features

- Text input for describing software bugs
- Programming language selection
- AI-generated analysis of programming problems
- Possible causes of bugs
- Suggested debugging steps and fixes
- Additional information requests when the problem
  cannot be diagnosed from the description alone

## How the Application Works

1. The user enters a description of a software bug.
2. The user selects a programming language.
3. Streamlit processes the input.
4. The application sends the problem to Google's Gemini API.
5. Gemini generates an analysis and troubleshooting suggestions.
6. Streamlit displays the response on the webpage.

## Project Files

- app.py — Streamlit interface and Gemini API integration
- requirements.txt — Python dependencies
- README.md — Project documentation

## Running the Application

The application is publicly available at:

https://mrammarhaf-ai-bug-assistant.streamlit.app/

To run the application locally:

1. Install Python.
2. Download or clone the GitHub repository.
3. Install the dependencies:

   pip install -r ai-assistant/requirements.txt

4. Configure a GEMINI_API_KEY using Streamlit Secrets.
5. Start the application:

   streamlit run ai-assistant/app.py

## Security

The Gemini API key is stored privately using Streamlit
Secrets. It is not included in the public GitHub source code.

## Limitations

AI-generated suggestions are not guaranteed to be correct.
The assistant cannot automatically inspect a user's
computer or execute their code.

Its recommendations depend on the information provided by
the user. The application may also experience API errors
or temporary service limits.

## Development Process

The project was developed incrementally:

1. Built the initial Streamlit interface.
2. Published the source code on GitHub.
3. Deployed the application using Streamlit Community Cloud.
4. Integrated the Gemini API.
5. Tested the application using C++ debugging examples.
6. Troubleshot an API overload error and changed models.
7. Verified that the application generates AI responses.

## Future Improvements

Potential improvements include support for uploading
code files, exporting bug reports, and more detailed
debugging assistance.
