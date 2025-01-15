async function fetchData() {
    try {
        const usersResponse = await fetch('https://jsonplaceholder.typicode.com/users');
        const users = await usersResponse.json();

        const postsResponse = await fetch('https://jsonplaceholder.typicode.com/posts');
        const posts = await postsResponse.json();

        return { users, posts };
    } catch (error) {
        console.error('Error fetching data:', error);
    }
}

document.addEventListener('DOMContentLoaded', () => {
    fetchData().then(data => {
        if (!data) return;

        const { users, posts } = data;
        const tableBody = document.querySelector('table tbody');

        users.forEach(user => {
            const userPosts = posts.filter(post => post.userId === user.id);
            
            const postsList = userPosts.map(post => `
                <li>${post.title}</li>
            `).join('');

            const row = document.createElement('tr');
            row.innerHTML = `
                <td>${user.username}</td>
                <td>${user.email}</td>
                <td>${user.company.name}</td>
                <td>${user.address.geo.lat + ' , '+ user.address.geo.lng}</td>
                <td>
                    <ol>${postsList}</ol>
                </td>
            `;
            tableBody.appendChild(row);
        });
    });
});
