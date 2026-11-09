
import streamlit as st
from google import genai

st.set_page_config(
    page_title="AI Bug Report Assistant",
    page_icon="🛠️"
)

st.title("AI Bug Report Assistant")

st.write(
    "Describe a software bug and get AI-powered "
    "suggestions to help troubleshoot the issue."
)

bug_description = st.text_area(
    "Describe the bug",
    placeholder="Example: My application crashes when I click Save.",
    height=150,
    max_chars=3000
)

programming_language = st.selectbox(
    "Programming Language",
    ["C++", "Python", "Java", "JavaScript", "Other"]
)

if st.button("Analyze Bug"):
    if not bug_description.strip():
        st.warning("Please describe the bug first.")
    else:
        prompt = f"""
You are a helpful software debugging assistant.

Analyze the following programming problem.

Programming language: {programming_language}

Bug description:
{bug_description}

Organize your response into these sections:

1. Problem Summary
2. Possible Causes
3. Debugging Steps
4. Suggested Fixes
5. Additional Information Needed

Explain everything clearly and provide practical
suggestions. Do not assume you have seen the source
code if it has not been provided. If the cause is
uncertain, explain what should be checked first.
"""

        try:
            with st.spinner("Analyzing your bug..."):
                client = genai.Client(
                    api_key=st.secrets["GEMINI_API_KEY"]
                )

                response = client.models.generate_content(
                    model="gemini-3.8-flash",
                    contents=prompt
                )

            if response.text:
                st.subheader("AI Analysis")
                st.markdown(response.text)
            else:
                st.warning(
                    "Gemini did not return an analysis. "
                    "Please try again."
                )

        except Exception:
            st.error(
                "Unable to analyze the bug. "
                "Check the Streamlit app logs, "
                "Gemini API access, and usage limits."
            )
