CREATE TABLE projects (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE tasks (
    id SERIAL PRIMARY KEY,
    project_id INT NOT NULL REFERENCES projects(id) ON DELETE CASCADE,
    task_name VARCHAR(255) NOT NULL,
    status VARCHAR(50) DEFAULT 'pending'
);

CREATE VIEW project_summary AS
SELECT
    p.id AS project_id,
    p.name AS project_name,
    COUNT(t.id) AS total_tasks,
    COUNT(CASE WHEN t.status = 'completed' THEN 1 END) AS completed_tasks
FROM
    projects p
LEFT JOIN
    tasks t
ON
    p.id = t.project_id
GROUP BY
    p.id, p.name;

CREATE OR REPLACE FUNCTION add_project_with_tasks(
    project_name VARCHAR,
    task_list TEXT[]
) RETURNS VOID AS $$
DECLARE
    new_project_id INT;
BEGIN
    INSERT INTO projects (name) VALUES (project_name) RETURNING id INTO new_project_id;

    IF task_list IS NOT NULL THEN
        INSERT INTO tasks (project_id, task_name)
        SELECT new_project_id, UNNEST(task_list);
    END IF;
END;
$$ LANGUAGE plpgsql;

SELECT add_project_with_tasks('New project', ARRAY['Task 1', 'Task 2', 'Task 3']);
