erDiagram
    USER_TYPE ||--o{ USER : "所属する"
    USER ||--o{ RESERVATION : "予約する"
    HOTEL ||--o{ RESERVATION : "予約される"
    RESERVATION ||--o| PAYMENT : "決済する"

    USER_TYPE {
        bigint user_type_id PK
        varchar user_type_name
    }

    USER {
        bigint user_id PK
        varchar user_name
        bigint user_type_id FK
    }

    RESERVATION {
        bigint reservation_id PK
        bigint user_id FK
        bigint hotel_id FK
        date check_in
        date check_out
    }

    HOTEL {
        bigint hotel_id PK
        varchar hotel_name
    }

    PAYMENT {
        bigint payment_id PK
        bigint reservation_id FK
        varchar payment_type
        varchar payment_status
    }

erDiagram
    USER_TYPE ||--o{ USER : "所属する"
    USER ||--o{ RESERVATION : "予約する"
    HOTEL ||--o{ RESERVATION : "予約される"
    RESERVATION ||--o| PAYMENT : "決済する"
    RESERVATION ||--o| CANCELLATION : "キャンセルされる"

    USER_TYPE {
        int user_type_id PK
        varchar user_type_name
    }

    USER {
        int user_id PK
        varchar user_name
        int user_type_id FK
    }

    RESERVATION {
        int reservation_id PK
        int user_id FK
        int hotel_id FK
        date check_in_date
        date check_out_date
        varchar reservation_status
        timestamp reserved_at
    }

    HOTEL {
        int hotel_id PK
        varchar hotel_name
    }

    PAYMENT {
        int payment_id PK
        int reservation_id FK
        varchar payment_type
        varchar payment_status
    }

    CANCELLATION {
        int cancellation_id PK
        int reservation_id FK
        timestamp cancelled_at
        varchar cancellation_reason
        int refund_amount
        varchar refund_status
    }

erDiagram
    USERS ||--o{ POSTS : "投稿する"
    USERS ||--o{ FOLLOWS : "フォローする"
    USERS ||--o{ FOLLOWS : "フォローされる"
    USERS ||--o{ LIKES : "いいねする"
    POSTS ||--o{ LIKES : "いいねされる"

    USERS {
        int user_id PK
        varchar user_name
        varchar email
    }

    POSTS {
        int post_id PK
        int user_id FK
        text content
        timestamp posted_at
    }

    FOLLOWS {
        int follower_id PK, FK
        int followee_id PK, FK
        timestamp followed_at
    }

    LIKES {
        int user_id PK, FK
        int post_id PK, FK
        timestamp liked_at
    }