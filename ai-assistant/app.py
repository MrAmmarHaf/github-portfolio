
import streamlit as st

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
    height=150
)

programming_language = st.selectbox(
    "Programming Language",
    ["C++", "Python", "Java", "JavaScript", "Other"]
)

if st.button("Analyze Bug"):
    if not bug_description.strip():
        st.warning("Please describe the bug first.")
    else:
        st.info(
            "The interface is working. "
            "We'll connect the AI model next."
        )
